#pragma once
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <sys/epoll.h>
#include "Threadspoll.h"
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include "mypb.pb.h"


//·Ç×èÈûI/O + ±ßÔµ´¥·¢


class Server {

	friend class Threadspoll;

private:

	uint16_t m_port;
	std::string m_sqlUser;
	std::string m_sqlPassword;
	int m_backblog;

	int m_fd_server;
	sockaddr_in m_serverAddr;
	int m_epoll_fd;
	struct epoll_event m_events[10240];
	int m_flags;

	int m_len_header;

public:
	static size_t m_len_header;


private:
	Threadspoll& m_threadspoll = Threadspoll::getPoll();


public:

	Server(std::string user, std::string password, uint16_t port = 23720, int backlog = 64);
	void request_enqueue(int client_fd);
	void init();
	void run();
	void cnn_accept();

	static void handle_request(int client_fd, char* buffer);    
	static void exe_login(int len, char* buffer);
	static void exe_register(int len, char* buffer);
	static void exe_getdata(int len, char* buffer);
	static void close_cnn(int client_fd);
};