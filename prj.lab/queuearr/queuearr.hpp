#pragma once
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include <complex/complex.hpp>
#include <iostream>

class QueueArr {
public:
	QueueArr() = default;
	~QueueArr() { delete[] data_; }
	QueueArr(const QueueArr& rhs);
	QueueArr& operator=(const QueueArr& rhs);
	QueueArr(QueueArr&&);
	QueueArr& operator=(QueueArr&&);
	void Pop();
	void Push(const Complex& rhs);
	void Clear();
	Complex& Top();
	const Complex& Top() const;
	bool IsEmpty();
private:
	Complex* data_ = nullptr;
	int size_ = 0;
	int i_top_ = -1;
};

#endif