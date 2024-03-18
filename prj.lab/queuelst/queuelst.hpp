#pragma once
#ifndef QUEUELST_HPP
#define QUEUELST_HPP
#include <complex/complex.hpp>
#include <iostream>

class QueueLst {
public:
	QueueLst() = default;
	~QueueLst() { while (!IsEmpty()) { Pop(); } };
	QueueLst(const QueueLst& rhs);
	QueueLst(QueueLst&&);
	QueueLst& operator=(QueueLst&&);
	QueueLst& operator=(const QueueLst& rhs);
	void Pop();
	void Push(const Complex& a);
	bool IsEmpty() const;
	Complex& Top();
	const Complex& Top() const;
	void Clear();
private:
	struct Node {
		Complex val;
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

#endif