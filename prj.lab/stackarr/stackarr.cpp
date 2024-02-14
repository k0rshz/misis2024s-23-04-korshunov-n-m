#include "stackarr/stackarr.hpp"

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