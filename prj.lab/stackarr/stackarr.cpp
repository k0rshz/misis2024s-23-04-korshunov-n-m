#include "complex/complex.hpp"
#include <iostream>

class StackArr {
public:
	StackArr() = default;
	~StackArr() {
		delete[] data_;
	}
	StackArr(const StackArr&);
	StackArr& operator=(const StackArr&);
	void Pop();
	void Push(Complex a);
	bool IsEmpty();
	Complex Top();
private:
	Complex* data_ = nullptr;
	int capacity_ = 0;
	int topInd_ = -1;
};

void StackArr::Push(Complex a) {
	if (topInd_ == capacity_ - 1) {
		int ncapacity = capacity_ + 1;
		Complex* ndata = new Complex[ncapacity];
		topInd_ += 1;
		for (int i = 0; i < topInd_; ++i) {
			ndata[i] = data_[i];
		}
		delete[] data_;
		capacity_ = ncapacity;
		data_ = ndata;
	}
	data_[topInd_] = a;
}

void StackArr::Pop() {
	Complex* ndata = new Complex[capacity_ - 1];
	for (int i = 0; i < topInd_; ++i) {
		ndata[i] = data_[i];
	}
	topInd_ -= 1;
	delete[] data_;
	data_ = ndata;
}

Complex StackArr::Top() {
	return data_[topInd_];
}

bool StackArr::IsEmpty() {
	return topInd_ == -1;
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