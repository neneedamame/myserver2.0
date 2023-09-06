#pragma once
#include <thread>
#include <vector>
#include <sys/epoll.h>
#include <unordered_map>
#include <functional>
#include "Server.h"
#include "Log.h"
#include "Sql_cnn_poll.h"


class Threadspoll {
private:
	bool m_stop;
	int m_numThreads;
	std::vector<std::thread> m_threads;
	
	Threadspoll(int numThreads = 16);
	~Threadspoll();

public:
	Threadspoll(const Threadspoll&) = delete;
	Threadspoll& operator=(const Threadspoll&) = delete;

	void start();

	static Threadspoll& getPoll();
};
