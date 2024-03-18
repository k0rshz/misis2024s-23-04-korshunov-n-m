#include "stackarr/stackarr.hpp"

StackArr::StackArr(const StackArr& rhs) {
	size_ = rhs.size_;
	i_top_ = rhs.i_top_;
	data_ = new Complex[size_];
	for (int i = 0; i <= i_top_; ++i) {
		data_[i] = rhs.data_[i];
	}
}

StackArr::StackArr(StackArr&& other)
	: data_{ other.data_ },
	size_{ other.size_ },
	i_top_{ other.i_top_ } {
	other.data_ = nullptr;
	other.i_top_ = -1;
	other.size_ = 0;
}

StackArr& StackArr::operator=(const StackArr& rhs) {
	delete[] data_;
	size_ = rhs.size_;
	i_top_ = rhs.i_top_;
	data_ = new Complex[size_];
	for (int i = 0; i <= i_top_; ++i) {
		data_[i] = rhs.data_[i];
	}
	return *this;
}

StackArr& StackArr::operator=(StackArr&& other) {
	if (this != &other) {
		delete[] data_;
		data_ = other.data_;
		i_top_ = other.i_top_;
		size_ = other.size_;
		other.data_ = nullptr;
		other.size_ = 0;
		other.i_top_ = -1;
	}
	return *this;
}

void StackArr::Push(const Complex& a) {
	if (i_top_ == size_ - 1) {
		int ncapacity = (size_ + 1) * 2;
		Complex* ndata = new Complex[ncapacity];
		for (int i = 0; i <= i_top_; ++i) {
			ndata[i] = data_[i];
		}
		delete[] data_;
		size_ = ncapacity;
		data_ = ndata;
	}
	i_top_ += 1;
	data_[i_top_] = a;
}

void StackArr::Pop() {
	if (!IsEmpty()) {
		i_top_ -= 1;
	}
}

Complex& StackArr::Top() {
	if (i_top_ < 0) {
		throw std::logic_error("StackArr - try get top form empty stack.");
	}
	return data_[i_top_];
}

const Complex& StackArr::Top() const {
	if (i_top_ < 0) {
		throw std::logic_error("StackArr - try get top form empty stack.");
	}
	return data_[i_top_];
}

bool StackArr::IsEmpty() const {
	return i_top_ == -1;
}

void StackArr::Clear() {
	data_ = nullptr;
	size_ = 0;
	i_top_ = -1;
}