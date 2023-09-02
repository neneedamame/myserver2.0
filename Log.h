#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <mutex>

class Log {
public:
	static Log& getInstance() {
		static Log log;
		return log;
	}

	void writeError(std::string errorMsg) {
		std::unique_lock<std::mutex> lock(m_log_mtx);
		if (!m_errorLog.is_open()) {
			m_errorLog.open("errorLog.txt");
		}
		m_errorLog << '[' << getTime() << "]  " << errorMsg << std::endl;
	}

	void writeRun(std::string runMsg) {
		std::unique_lock<std::mutex> lock(m_log_mtx);
		if (!m_runLog.is_open()) {
			m_runLog.open("runLog.txt");
		}
		m_errorLog << '[' << getTime() << "]  " << runMsg << std::endl;
	}

	char* getTime() {
		static char time[21];
		time_t t = std::time(NULL);
		tm* t_tm = std::localtime(&t);
		std::strftime(time, sizeof(time), "%Y-%m-%d %H:%M:%S", t_tm);
		return time;
	}


private:
	Log() {
		m_errorLog.open("errorLog.txt", std::ios::out);
		m_runLog.open("runLog.txt", std::ios::out);
	}



	std::ofstream m_errorLog;
	std::ofstream m_runLog;
	std::mutex m_log_mtx;


public:
	Log(const Log&) = delete;
	Log& operator=(const Log&) = delete;
};


#define WRITE_ERROR(error_msg) Tasks.enqueue([=] { Log::getInstance().writeError(error_msg); });
#define WRITE_RUN(run_msg) Tasks.enqueue([=]{ Log::getInstance().writeRun(run_msg); });