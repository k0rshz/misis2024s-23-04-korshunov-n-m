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
	void pop();
	void push(const Complex& a);
	bool isEmpty() const;
	Complex& top();
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

void StackArr::push(const Complex& a) {
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

void StackArr::pop() {
	Complex* ndata = new Complex[capacity_];
	for (int i = 0; i < topInd_; ++i) {
		ndata[i] = data_[i];
	}
	topInd_ -= 1;
	delete[] data_;
	data_ = ndata;
}

Complex& StackArr::top() {
	return data_[topInd_];
}

bool StackArr::isEmpty() const {
	return topInd_ == -1;
}

int main() {
	Complex a{ 1.5, 2.0 }, b{ 3.1, 4.9 }, c{ 2.8, 3.1 };
	StackArr s;
	std::cout << s.isEmpty() << std::endl;
	s.push(a);
	std::cout << s.isEmpty() << std::endl;
	std::cout << s.top() << std::endl;
	s.push(b);
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.push(c);
	std::cout << s.top() << std::endl;
}