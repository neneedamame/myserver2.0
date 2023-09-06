#include "Timer.h"

void Timer::add_cnn(int id, std::chrono::milliseconds wait_time, std::function<void()> cb)
{
    if (m_cnnRef.count(id) == 0)
    {
        m_cnnRef[id] = m_cnnList.emplace_back(id, std::chrono::high_resolution_clock::now() + wait_time, cb);
    }
    else
    {
        m_cnnList.renewal(m_cnnRef[id]);
    }
}

void Timer::work()
{
    auto curTime = std::chrono::high_resolution_clock::now();
    while (m_cnnList.gethead() != nullptr && m_cnnList.front().t < curTime)
    {
        m_cnnList.front().cb();
        clear(m_cnnList.front().id);
        m_cnnList.pop();
    }
}

void Timer::clear(const int &id)
{
    m_cnnRef.erase(id);
    epoll_ctl(m_server_ptr->m_epoll_fd, EPOLL_CTL_DEL, id, m_server_ptr->m_events);
}

Timer::Timer(Server *server_ptr)
{
    m_server_ptr = server_ptr;
}

