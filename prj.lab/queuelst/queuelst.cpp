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
	Node* temp = rhs.head_;
	head_ = temp;
	Node* prev = head_;
	temp = temp->next;
	while (temp != nullptr) {
		prev->next = temp;
		prev = prev->next;
		temp = temp->next;
	}
}
