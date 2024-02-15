#include "stacklst/stacklst.hpp"

//StackLst::StackLst(const StackLst& rhs) {
//	if (rhs.head_ == nullptr) {
//		head_ = nullptr;
//		return;
//	}
//
//}

bool StackLst::IsEmpty() const {
	return head_ == nullptr;
}

Complex& StackLst::Top() {
	return head_->v_;
}

void StackLst::Push(const Complex& a) {
	Node* nhead = new Node;
	nhead->v_ = a;
	nhead->next_ = head_;
	head_ = nhead;
}

void StackLst::Pop() {
	if (head_ == nullptr) {
		return;
	}
	Node* p = head_;
	head_ = head_->next_;
	delete p;
}

void StackLst::Clear() {
	head_ = nullptr;
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
