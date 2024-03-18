#pragma once
#ifndef STACKLST_HPP
#define STACKLST_HPP
#include "complex/complex.hpp"
#include <iostream>

class StackLst {
public:
	StackLst() = default;
	~StackLst() { while (!IsEmpty()) { Pop(); } };
	StackLst(const StackLst& rhs);
	StackLst& operator=(const StackLst& rhs);
	StackLst(StackLst&& other);
	StackLst& operator=(StackLst&& other);
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
};

#endif