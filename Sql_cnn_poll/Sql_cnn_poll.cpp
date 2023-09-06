#include "Sql_cnn_poll.h"

LockFreeQueue<MYSQL *> Sql_cnn_poll::Connections;

void Sql_cnn_poll::init(string user, string password, string dbName, string host, int num_cnnMax, unsigned int port)
{
    m_user = user;
    m_password = password;
    m_dbName = dbName;
    m_host = host;
    m_num_cnnMax = num_cnnMax;
    m_port = port;

    for (int i = 0; i < m_num_cnnMax; ++i)
    {
        MYSQL *connection = mysql_init(nullptr);
        if (connection)
        {
            if (mysql_real_connect(connection, m_host.c_str(), m_user.c_str(), m_password.c_str(), m_dbName.c_str(), m_port, nullptr, 0))
            {
                Connections.emplace(connection);
            }
            else
            {
                throw std::runtime_error("mysql connect failure");
            }
        }
        else
        {
            throw std::runtime_error("mysql init failure");
        }
    }
}
