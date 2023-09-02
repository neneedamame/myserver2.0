#pragma once
#include "LockFreeQueue.h"
#include <string>
#include <iostream>

using std::string;

class Sql_cnn_poll {

private:
	string m_user;
	string m_password;
	string m_dbName;
	string m_host;
	int m_num_cnnMax;
	unsigned int m_port;


	void init() {
		for (int i = 0; i < m_num_cnnMax; ++i) {
			MYSQL* connection = mysql_init(nullptr);
			if (connection) {
				if (mysql_real_connect(connection, m_host.c_str(), m_user.c_str(), m_password.c_str(), m_dbName.c_str(), m_port, nullptr, 0)) {
					Connections.emplace(connection);
				}
				else {
					throw std::runtime_error("mysql connect failure");
				}
			}
			else {
				throw std::runtime_error("mysql init failure");
			}
		}
	}

public:

	Sql_cnn_poll(string user, string password, string dbName, string host="127.0.0.1", int num_cnnMax=16, unsigned int port=3306) {
		m_user = user;
		m_password = password;
		m_dbName = dbName;
		m_host = host;
		m_num_cnnMax = num_cnnMax;
		m_port = port;
		init();
	}

};

class Sql_cnn {

private:
	MYSQL* m_sql_cnn;

public:
	Sql_cnn() {
		while (!Connections.pop(m_sql_cnn));
	}

	MYSQL* getCnn() {
		return m_sql_cnn;
	}

	~Sql_cnn() {
		Connections.emplace(m_sql_cnn);
	}
};