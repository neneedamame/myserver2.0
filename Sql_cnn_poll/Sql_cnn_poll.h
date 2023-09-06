#pragma once
#include "LockFreeQueue.h"
#include <string>
#include <iostream>

using std::string;

class Sql_cnn_poll
{

private:
	string m_user;
	string m_password;
	string m_dbName;
	string m_host;
	int m_num_cnnMax;
	unsigned int m_port;

public:
	static LockFreeQueue<MYSQL*> Connections;

public:
	void init(string user, string password, string dbName, string host = "127.0.0.1", int num_cnnMax = 16, unsigned int port = 3306);
};

class Sql_cnn
{

private:
	MYSQL *m_sql_cnn;

public:
	Sql_cnn()
	{
		while (!Sql_cnn_poll::Connections.pop(m_sql_cnn));
	}

	MYSQL *getCnn()
	{
		return m_sql_cnn;
	}

	~Sql_cnn()
	{
		Sql_cnn_poll::Connections.emplace(m_sql_cnn);
	}
};