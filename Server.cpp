#include "Server.h"


//������epoll��ʼ��
void Server::init() {

	m_epoll_fd = epoll_create(10);
	if (-1 == m_epoll_fd) {
		throw std::runtime_error("epoll create failure");
	}


	m_fd_server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (-1 == m_fd_server) {
		throw std::runtime_error("server socket create failure");
	}


	//����server_fd��acceptΪ������
	m_flags = fcntl(m_fd_server, F_GETFL);
	fcntl(m_fd_server, F_GETFL, m_flags | O_NONBLOCK);


	m_serverAddr.sin_family = AF_INET;
	m_serverAddr.sin_port = htons(m_port);
	m_serverAddr.sin_addr.s_addr = INADDR_ANY;


	if (-1 == bind(m_fd_server, (sockaddr*)&m_serverAddr, sizeof(sockaddr))) {
		throw std::runtime_error("server bind error");
	}


	if (-1 == listen(m_fd_server, 10000)) {
		throw std::runtime_error("server listen error");
	}

}


//���ݿ��û��������룻�������˿ںţ�listen�����ȴ���
Server::Server(std::string user, std::string password, uint16_t port, int backlog) {
	m_sqlUser = user;
	m_sqlPassword = password;
	m_port = port;
	m_backblog = backlog;
	
}


//�Ѵ�����������������������̳߳ش���
void Server::request_enqueue(int client_fd) {
	auto task = std::bind(Server::handle_request, client_fd, std::placeholders::_1);
	Tasks.emplace(task);
}

  
//����ͻ�������
void Server::handle_request(int client_fd, char* buffer) {
	
}


//�����յ�������ע�ᵽ�ں�
void Server::cnn_accept() {

	sockaddr_in cAddr;
	socklen_t cAddr_len = sizeof(sockaddr);
	epoll_event event;
	event.events = EPOLLIN | EPOLLET;
	int cSock = -1;

	for (int i = 0; i < m_backblog; ++i) {

		if ((cSock = accept(m_fd_server, (sockaddr*)&cAddr, &cAddr_len)) == -1) {
			break;
		}
		event.data.fd = cSock;
		epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, cSock, &event);
	}
}


//һ������������
void Server::run() {

	init();

	socklen_t addrlen = sizeof(sockaddr);
	while (true) {

	}
}


