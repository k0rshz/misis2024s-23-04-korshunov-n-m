#pragma once
#ifndef QUEUELSTPR_HPP
#define QUEUELSTPR_HPP
#include <iostream>

class QueueLstPr {
public:
	QueueLstPr() = default;
	~QueueLstPr() {
		while (!IsEmpty()) { Pop(); }
	};
	QueueLstPr(const QueueLstPr& rhs);
	QueueLstPr& operator=(const QueueLstPr& rhs);
	QueueLstPr(QueueLstPr&&);
	QueueLstPr& operator=(QueueLstPr&&);
	void Clear();
	void Push(const float& rhs);
	bool IsEmpty() const;
	void Pop();
	float& Top();
	const float& Top() const;
private:
	struct Node {
		float val;
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

#endif