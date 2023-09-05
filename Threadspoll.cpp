#include "Threadspoll.h"

Threadspoll::Threadspoll(int numThreads)
{
    m_numThreads = numThreads;
    m_stop = true;
}

Threadspoll::~Threadspoll()
{
    m_stop = true;
}

void Threadspoll::start()
{
    if (!m_stop)
    {
        return;
    }

    for (int i = 0; i < m_numThreads; ++i)
    {
        m_threads.emplace_back([this]
        {
			char buffer[10240];
			while (!m_stop) {
				std::function<void(char* buffer)> task;
				if (Server::Tasks.pop(task)) {
					task(buffer);
				}
			} 
        });
    }
}

Threadspoll& Threadspoll::getPoll()
{
    static Threadspoll threadspoll;
    return threadspoll;
} 