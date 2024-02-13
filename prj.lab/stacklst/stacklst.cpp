#include "complex/complex.hpp"
#include <iostream>

class StackLst {
public:
	StackLst() = default;
	~StackLst() {};
	StackLst(const StackLst& rhs);
	StackLst& operator=(const StackLst& rhs);
	void Pop();
	void Push(const Complex& a);
	bool IsEmpty() const;
	Complex& Top();
	void Clear();
private:
	struct Node {
		Complex v_;
		Node* next_ = nullptr;
	};
	Node* head_ = nullptr;
};

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
	head_ = head_->next_;
}

void StackLst::Clear() {
	head_ = nullptr;
}

int main() {
	StackLst a;
	Complex z{ 1.0, 2.1 }, x{ 4.5, 10.9 };
	std::cout << a.IsEmpty() << std::endl;
	a.Push(z);
	std::cout << a.Top() << std::endl;
	std::cout << a.IsEmpty() << std::endl;
	a.Push(x);
	std::cout << a.Top() << std::endl;
	a.Pop();
	std::cout << a.Top() << std::endl;
	return 0;
}
