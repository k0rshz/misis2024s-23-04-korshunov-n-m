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
	void Pop();
	void Push(const Complex& a);
	bool IsEmpty() const;
	Complex& Top();
	void Clear();
private:
	Complex* data_ = nullptr;
	int capacity_ = 0;
	int topInd_ = -1;
};

#endif