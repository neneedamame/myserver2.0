#pragma once
#include <thread>
#include <vector>
#include "Log.h"
#include <sys/epoll.h>
#include <unordered_map>
#include "Sql_cnn_poll.h"
#include <functional>



class Threadspoll {
private:
	bool m_stop;
	int m_numThreads;
	std::vector<std::thread> m_threads;
	

	Threadspoll(int numThreads = 16) {
		m_numThreads = numThreads;
		m_stop = true;
	}


public:
	Threadspoll(const Threadspoll&) = delete;
	Threadspoll& operator=(const Threadspoll&) = delete;


	~Threadspoll() {
		m_stop = true;
	}

	void start() {
		if (!m_stop) {
			return;
		}

		for (int i = 0; i < m_numThreads; ++i) {
			m_threads.emplace_back([this] {
				char buffer[10240];
				while (!m_stop) {
					std::function<void(char* buffer)> task;
					if (Tasks.pop(task)) {
						task(buffer);
					}
				}
			});
		}
	}

	static Threadspoll& getPoll() {
		static Threadspoll threadspoll;
		return threadspoll;
	}
};


