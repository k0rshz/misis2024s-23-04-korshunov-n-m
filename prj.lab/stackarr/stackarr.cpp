#include "complex/complex.hpp"
#include <iostream>

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

StackArr::StackArr(const StackArr& rhs) {
	capacity_ = rhs.capacity_;
	topInd_ = rhs.topInd_;
	data_ = new Complex[capacity_];
	for (int i = 0; i <= topInd_; ++i) {
		data_[i] = rhs.data_[i];
	}
}

StackArr& StackArr::operator=(const StackArr& rhs) {
	delete[] data_;
	capacity_ = rhs.capacity_;
	topInd_ = rhs.topInd_;
	data_ = new Complex[capacity_];
	for (int i = 0; i <= topInd_; ++i) {
		data_[i] = rhs.data_[i];
	}
	return *this;
}

void StackArr::Push(const Complex& a) {
	if (topInd_ == capacity_ - 1) {
		int ncapacity = (capacity_ + 1) * 2;
		Complex* ndata = new Complex[ncapacity];
		for (int i = 0; i <= topInd_; ++i) {
			ndata[i] = data_[i];
		}
		delete[] data_;
		capacity_ = ncapacity;
		data_ = ndata;
	}
	topInd_ += 1;
	data_[topInd_] = a;
}

void StackArr::Pop() {
	Complex* ndata = new Complex[capacity_];
	for (int i = 0; i < topInd_; ++i) {
		ndata[i] = data_[i];
	}
	topInd_ -= 1;
	delete[] data_;
	data_ = ndata;
}

Complex& StackArr::Top() {
	return data_[topInd_];
}

bool StackArr::IsEmpty() const {
	return topInd_ == -1;
}

void StackArr::Clear() {
	data_ = nullptr;
	capacity_ = 0;
	topInd_ = -1;
}

int main() {
	Complex a{ 1.5, 2.0 }, b{ 3.1, 4.9 }, c{ 2.8, 3.1 };
	StackArr s;
	std::cout << s.IsEmpty() << std::endl;
	s.Push(a);
	std::cout << s.IsEmpty() << std::endl;
	std::cout << s.Top() << std::endl;
	s.Push(b);
	std::cout << s.Top() << std::endl;
	s.Pop();
	std::cout << s.Top() << std::endl;
	s.Push(c);
	std::cout << s.Top() << std::endl;
}