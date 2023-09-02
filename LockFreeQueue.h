#pragma once
#include <atomic>
#include <mysql/mysql.h>
#include <functional>

template<class T>
class LockFreeQueue {
public:

	LockFreeQueue() {
		m_head.store(nullptr);
		m_tail.store(nullptr);
	}


	void emplace(T t) {
		queueNode* newNode = new queueNode(t);
		queueNode* preNode = std::atomic_exchange(&m_tail, newNode);
		if (preNode == nullptr) {
			m_head.store(newNode);
		}
		else {
			preNode->next = newNode;
		}
	}


	bool pop(T& t) {
		queueNode* curHead = nullptr;
		do {
			curHead = m_head.load();
		} while (curHead != nullptr && !m_head.compare_exchange_weak(curHead, curHead->next));
		if (curHead != nullptr) {
			t = std::move(curHead->task);
			delete curHead;
			return true;
		}
		delete curHead;
		return false;
	}


	template<class F, class ...Args>
	void enqueue(F&& f, Args&& ...args) {
		T task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
		emplace(task);
	}


private:

	struct queueNode {
		struct queueNode* next;
		T task;
		queueNode(T& t) :next(nullptr), task(std::move(t)) {};
	};

	std::atomic<queueNode*> m_head, m_tail;
};

static LockFreeQueue<std::function<void(char* buffer)>> Tasks;
static LockFreeQueue<MYSQL*> Connections;