#include "queuelstpr/queuelstpr.hpp"

bool QueueLstPr::IsEmpty() const {
	return head_ == nullptr;
}

float& QueueLstPr::Top() {
	if (IsEmpty()) {
		throw std::logic_error("QueueLst - try get top form empty queue.");
	}
	return head_->val;
}

const float& QueueLstPr::Top() const {
	if (IsEmpty()) {
		throw std::logic_error("QueueLst - try get top form empty queue.");
	}
	return head_->val;
}

void QueueLstPr::Pop() {
	if (head_ == nullptr) {
		return;
	}
	Node* p = head_;
	head_ = head_->next;
	delete p;
}

void QueueLstPr::Clear() {
	while (!IsEmpty()) {
		Pop();
	}
}

void QueueLstPr::Push(const float& rhs) {
	if (head_ == nullptr) {
		Node* nhead = new Node;
		nhead->val = rhs;
		head_ = nhead;
	}
	else {
		if (head_->val > rhs) {
			Node* a = new Node;
			a->val = rhs;
			a->next = head_;
			head_ = a;
		}
		else {
			Node* b = new Node;
			if (head_->next == nullptr) {
				b->val = rhs;
				b->next = nullptr;
				head_->next = b;
			}
			else {
				Node* prev = new Node;
				prev = head_;
				b = head_->next;
				int flag = 0;
				while (b != nullptr && flag!=1) {
					if (b->val > rhs) {
						Node* a = new Node;
						a->val = rhs;
						a->next = b;
						prev->next = a;
						flag = 1;
					}
					else {
						prev = b;
						b = b->next;
					}
				}
			}
		}
	}
}
