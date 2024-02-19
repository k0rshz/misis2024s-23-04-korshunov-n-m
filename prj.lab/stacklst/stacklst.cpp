#include "stacklst/stacklst.hpp"

StackLst::StackLst(const StackLst& rhs) {
	if (rhs.head_ == nullptr) {
		head_ = nullptr;
		return;
	}
	head_ = new Node;
	head_->val = rhs.head_->val;
	Node* a = head_;
	Node* prev = head_;
	while (a->next != nullptr) {
		Node* nhead = new Node;
		a = a->next;
		prev->next = nhead;
		a->val = a->val;
		prev = nhead;
	}
}

StackLst& StackLst::operator=(const StackLst& rhs) {
	Clear();
	if (rhs.head_ == nullptr) {
		return *this;
	}
	head_ = new Node;
	head_->val = rhs.head_->val;
	Node* a = head_;
	Node* prev = head_;
	while (a->next != nullptr) {
		Node* nhead = new Node;
		a = a->next;
		prev->next = nhead;
		a->val = a->val;
		prev = nhead;
	}
	return *this;
}

bool StackLst::IsEmpty() const {
	return head_ == nullptr;
}

Complex& StackLst::Top() {
	if (head_ == nullptr) {
		throw std::logic_error("StackArr - try get top form empty stack.");
	}
	return head_->val;
}

const Complex& StackLst::Top() const {
	if (head_ == nullptr) {
		throw std::logic_error("StackArr - try get top form empty stack.");
	}
	return head_->val;
}

void StackLst::Push(const Complex& a) {
	Node* nhead = new Node;
	nhead->val = a;
	nhead->next = head_;
	head_ = nhead;
}

void StackLst::Pop() {
	if (head_ == nullptr) {
		return;
	}
	Node* p = head_;
	head_ = head_->next;
	delete p;
}

void StackLst::Clear() {
	while (!IsEmpty()) {
		Pop();
	}
}

//int main() {
//	StackLst a;
//	Complex z{ 1.0, 2.1 }, x{ 4.5, 10.9 };
//	std::cout << a.IsEmpty() << std::endl;
//	a.Push(z);
//	std::cout << a.Top() << std::endl;
//	std::cout << a.IsEmpty() << std::endl;
//	a.Push(x);
//	std::cout << a.Top() << std::endl;
//	a.Pop();
//	std::cout << a.Top() << std::endl;
//	return 0;
//}
