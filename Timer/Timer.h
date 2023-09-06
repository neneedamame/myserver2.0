#pragma once
#include <chrono>
#include <functional>
#include <unordered_map>
#include "Server.h"

class Server;

template <class T>
class List
{
public:
	struct Node
	{
		Node *pre;
		Node *next;
		T val;
		Node(T &t) : pre(nullptr), next(nullptr), val(std::move(t)){};

		Node *&operator++()
		{
			this = this->next;
			return this;
		}

		Node *operator++(int)
		{
			Node *temp = this;
			this = this->next;
			return temp;
		}
	};

private:
	Node *head;
	Node *tail;

public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}

	Node *push_back(T &t)
	{
		Node *node = new Node(t);
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			node->pre = tail;
			tail->next = node;
			tail = node;
		}
		return node;
	}

	template <class... Args>
	Node *emplace_back(Args &&...args)
	{
		T t(std::forward<Args>(args)...);
		return push_back(t);
	}

	void renewal(Node *node)
	{
		if (tail != node)
		{
			if (head != node)
			{
				node->pre->next = node->next;
				node->next->pre = node->pre;
			}
			else
			{
				head = node->next;
				node->next->pre = nullptr;
			}
		}
		return;
	}

	bool pop()
	{
		if (head != nullptr)
		{
			Node *temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		return false;
	}

	bool pop(T &t)
	{
		if (head != nullptr)
		{
			t = std::move(head->val);
			Node *temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		return false;
	}

	const T &front()
	{
		if (head)
		{
			return head->val;
		}
		throw std::runtime_error("List is empty, front() error");
	}

	Node *gethead()
	{
		return head;
	}

	~List()
	{
	}
};

class Timer
{
friend Server;

private:
	struct cnnTime
	{
		int id;
		std::chrono::high_resolution_clock::time_point t;
		std::function<void()> cb;

		cnnTime(int id, std::chrono::high_resolution_clock::time_point t, std::function<void()> cb)
		{
			this->id = std::move(id);
			this->t = std::move(t);
			this->cb = std::move(cb);
		}

		bool operator<(const cnnTime &tt)
		{
			return t < tt.t;
		}
	};

public:
	void add_cnn(int id, std::chrono::milliseconds wait_time = std::chrono::milliseconds(300000), std::function<void()> cb = {});
	void work();
	void clear(const int &id);
	Timer(Server *server_ptr);

private:
	List<cnnTime> m_cnnList;
	std::unordered_map<int, List<cnnTime>::Node *> m_cnnRef;
	Server *m_server_ptr;
};