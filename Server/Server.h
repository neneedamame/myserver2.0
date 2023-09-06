#pragma once
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <sys/epoll.h>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include "mypb.pb.h"
#include "Sql_cnn_poll.h"
#include "Threadspoll.h"
#include "Timer.h"


class Timer;

//·Ç×èÈûI/O + ±ßÔµ´¥·¢
class Server {

friend Timer;

private:

	uint16_t m_port;
	std::string m_sqlUser;
	std::string m_sqlPassword;
	std::string m_dbName;
	int m_backblog;

	int m_fd_server;
	sockaddr_in m_serverAddr;
	int m_epoll_fd;
	struct epoll_event m_events[10240];
	int m_flags;

	Sql_cnn_poll m_sql_poll;
	Timer* m_timer_ptr;

public:
	static size_t m_len_header;
	static LockFreeQueue<std::function<void(char* buffer)>> Tasks;

public:

	Server(std::string dbName, std::string user, std::string password, uint16_t port = 23720, int backlog = 64);
	void request_enqueue(int client_fd);
	void init();
	void run();
	void cnn_accept();
	void cnn_listen();
	void close_cnn(int client_fd);

	void handle_request(int client_fd, char* buffer);    
	void exe_login_register(int len, char* buffer, mypb::RequestType type);
	void exe_getdata(int len, char* buffer);
};
