#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP
#include <iostream>
#include "complex/complex.hpp"

class StackArr {
public:
	StackArr() = default;
	~StackArr() {
		delete[] data_;
	}
	StackArr(const StackArr& rhs);
	StackArr& operator=(const StackArr& rhs);
	StackArr(StackArr&& other);
	StackArr& operator=(StackArr&& other);
	void Pop();
	void Push(const Complex& a);
	bool IsEmpty() const;
	Complex& Top();
	const Complex& Top() const;
	void Clear();
private:
	Complex* data_ = nullptr;
	int size_ = 0;
	int i_top_ = -1;
};

#endif