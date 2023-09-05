#include "Server.h"

LockFreeQueue<std::function<void(char* buffer)>> Server::Tasks;
size_t Server::m_len_header=[]{
	mypb::dataHeader header;
	header.set_request(mypb::REQUEST_TYPE_GETDATA);
	header.set_bodysize(123);
	return header.ByteSizeLong();
}();

// ������epoll��ʼ����mysqlpoll��ʼ��
void Server::init()
{
	m_sql_poll.init(m_sqlUser, m_sqlPassword, m_dbName);

	m_epoll_fd = epoll_create(10);
	if (-1 == m_epoll_fd)
	{
		throw std::runtime_error("epoll create failure");
	}

	m_fd_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (-1 == m_fd_server)
	{
		throw std::runtime_error("server socket create failure");
	}

	// ����server_fd��acceptΪ������
	m_flags = fcntl(m_fd_server, F_GETFL);
	fcntl(m_fd_server, F_GETFL, m_flags | O_NONBLOCK);

	m_serverAddr.sin_family = AF_INET;
	m_serverAddr.sin_port = htons(m_port);
	m_serverAddr.sin_addr.s_addr = INADDR_ANY;

	if (-1 == bind(m_fd_server, (sockaddr *)&m_serverAddr, sizeof(sockaddr)))
	{
		throw std::runtime_error("server bind error");
	}

	if (-1 == listen(m_fd_server, 10000))
	{
		throw std::runtime_error("server listen error");
	}
}

// ���ݿ��û��������룻�������˿ںţ�listen�����ȴ���
Server::Server(std::string dbName, std::string user, std::string password, uint16_t port, int backlog)
{
	m_dbName = dbName;
	m_sqlUser = user;
	m_sqlPassword = password;
	m_port = port;
	m_backblog = backlog;
}

// �Ѵ�����������������������̳߳ش���
void Server::request_enqueue(int client_fd)
{
	auto task = std::bind(Server::handle_request, client_fd, std::placeholders::_1);
	Tasks.emplace(task);
}

// ����ͻ�������
void Server::handle_request(int client_fd, char *buffer)
{
	if (recv(client_fd, buffer, m_len_header, 0))
	{
		mypb::dataHeader header;
		header.ParseFromArray(buffer, m_len_header);
		if (recv(client_fd, buffer, header.bodysize(), 0) <= 0)
		{
			return;
		}

		switch (header.request())
		{
		case mypb::REQUEST_TYPE_LOGIN:
			Server::exe_login_register(header.bodysize(), buffer, mypb::REQUEST_TYPE_LOGIN);
			break;
		case mypb::REQUEST_TYPE_REGISTER:
			Server::exe_login_register(header.bodysize(), buffer, mypb::REQUEST_TYPE_REGISTER);
			break;
		case mypb::REQUEST_TYPE_GETDATA:
			Server::exe_getdata(header.bodysize(), buffer);
			break;
		default:
			Server::close_cnn(client_fd);
		}
	}
}

// ��¼��ע��
void Server::exe_login_register(int len, char *buffer, mypb::RequestType type)
{
	mypb::dataBody_login_register lr;
	lr.ParseFromArray(buffer, len);

	Sql_cnn cnn;
	MYSQL_BIND params[2];
	memset(params, 0, sizeof(params));
	MYSQL_STMT *stmt = mysql_stmt_init(cnn.getCnn());
	std::string query;
	MYSQL_BIND result_bind[2];

	params[0].buffer_type = MYSQL_TYPE_STRING;
	params[0].buffer = (void *)lr.username().c_str();
	params[0].buffer_length = lr.username().size();

	params[1].buffer_type = MYSQL_TYPE_STRING;
	params[1].buffer = (void *)lr.password().c_str();
	params[1].buffer_length = lr.password().size();

	if (type == mypb::REQUEST_TYPE_LOGIN)
	{
		query = "SELECT * FROM user_info WHERE username = ? AND password = ?";
		mysql_stmt_prepare(stmt, query.c_str(), query.size());
		mysql_stmt_bind_param(stmt, params);
		mysql_stmt_execute(stmt);
		mysql_stmt_bind_result(stmt, result_bind);
		mysql_stmt_store_result(stmt);
		my_ulonglong num_rows = mysql_stmt_num_rows(stmt);

		if (num_rows == 1)
		{
			// ��¼�ɹ�
		}
		else
		{
			// ��½ʧ��
		}
	}
	else
	{
		query = "SELECT * FROM user_info WHERE username = ?";
		mysql_stmt_prepare(stmt, query.c_str(), query.size());
		mysql_stmt_bind_param(stmt, &params[0]);
		mysql_stmt_execute(stmt);
		mysql_stmt_bind_result(stmt, result_bind);
		mysql_stmt_store_result(stmt);
		my_ulonglong num_rows = mysql_stmt_num_rows(stmt);

		if (num_rows == 1)
		{
			// ע��ʧ��
		}
		else
		{
			// ע��ɹ�
		}
	}

	mysql_stmt_close(stmt);
}

// �����յ�������ע�ᵽ�ں�
void Server::cnn_accept()
{

	sockaddr_in cAddr;
	socklen_t cAddr_len = sizeof(sockaddr);
	epoll_event event;
	event.events = EPOLLIN | EPOLLET;
	int cSock = -1;

	for (int i = 0; i < m_backblog; ++i)
	{

		if ((cSock = accept(m_fd_server, (sockaddr *)&cAddr, &cAddr_len)) == -1)
		{
			break;
		}
		event.data.fd = cSock;
		epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, cSock, &event);
	}
}

// ����
void Server::cnn_listen()
{
	int n = epoll_wait(m_epoll_fd, m_events, 10240, 0);
	for (int i = 0; i < n; ++i)
	{
		request_enqueue(m_events[i].data.fd);
	}
}

// һ������������
void Server::run()
{

	init();

	socklen_t addrlen = sizeof(sockaddr);
	while (true)
	{
		cnn_accept();
		cnn_listen();
	}
}

