#include "queuelst/queuelst.hpp"

bool QueueLst::IsEmpty() const {
	return head_ == nullptr;
}

Complex& QueueLst::Top() {
	if (IsEmpty()) {
		throw std::logic_error("QueueLst - try get top form empty queue.");
	}
	return head_->val;
}

const Complex& QueueLst::Top() const {
	if (IsEmpty()) {
		throw std::logic_error("QueueLst - try get top form empty queue.");
	}
	return head_->val;
}
void QueueLst::Push(const Complex& a) {
	if (head_ == nullptr) {
		Node* nhead = new Node;
		nhead->val = a;
		head_ = nhead;
		tail_ = nhead;
	}
	else {
		Node* ntail = new Node;
		tail_->next = ntail;
		ntail->val = a;
		tail_ = ntail;
		tail_->next = nullptr;
	}
}

QueueLst::QueueLst(QueueLst&& other) {
	head_ = other.head_;
	tail_ = other.tail_;
	other.head_ = nullptr;
	other.tail_ = nullptr;
}

QueueLst& QueueLst::operator=(QueueLst&& other) {
	if (this != &other) {
		Clear();
		head_ = other.head_;
		tail_ = other.tail_;
		other.head_ = nullptr;
		other.tail_ = nullptr;
	}
	return *this;
}

void QueueLst::Pop() {
	if (head_ == nullptr) {
		return;
	}
	Node* p = head_;
	head_ = head_->next;
	delete p;
}

void QueueLst::Clear() {
	while (!IsEmpty()) {
		Pop();
	}
}

QueueLst::QueueLst(const QueueLst& rhs) {
	if (rhs.IsEmpty()) {
		head_ = nullptr;
		tail_ = nullptr;
		return;
	}

	head_ = new Node;
	Node* a = head_;
	Node* b = rhs.head_;
	while (b->next != nullptr) {
		a->val = b->val;
		b = b->next;
		a->next = new Node;
		a = a->next;
	}
	a->val = b->val;
	tail_ = a;
}

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
	Clear();
	if (rhs.IsEmpty()) {
		return *this;
	}

	head_ = new Node;
	Node* a = head_;
	Node* b = rhs.head_;
	while (b->next != nullptr) {
		a->val = b->val;
		b = b->next;
		a->next = new Node;
		a = a->next;
	}
	a->val = b->val;
	tail_ = a;
	return *this;
}
