#include "queuearr/queuearr.hpp"

bool QueueArr::IsEmpty() {
	return i_top_ == -1 || i_top_ == size_;
}

void QueueArr::Clear() {
	delete[] data_;
	data_ = nullptr;
	size_ = 0;
}

Complex& QueueArr::Top() {
	return data_[i_top_];
}

const Complex& QueueArr::Top() const {
	return data_[i_top_];
}

void QueueArr::Push(const Complex& rhs) {
	Complex* ndata = new Complex[size_ + 1];
	for (int i = 0; i < size_; ++i) {
		ndata[i] = data_[i];
	}
	delete[] data_;
	size_ += 1;
	data_ = ndata;
	if (i_top_ == -1) {
		i_top_ += 1;
	}
	data_[size_ - 1] = rhs;
}

void QueueArr::Pop() {
	if (!IsEmpty()) {
		i_top_ += 1;
	}
}

QueueArr::QueueArr(const QueueArr& rhs) {
	Complex* ndata = new Complex[rhs.size_];
	for (int i = 0; i < rhs.size_; ++i) {
		ndata[i] = rhs.data_[i];
	}
	size_ = rhs.size_;
	i_top_ = rhs.i_top_;
	data_ = ndata;
}

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
	Complex* ndata = new Complex[rhs.size_];
	for (int i = 0; i < rhs.size_; ++i) {
		ndata[i] = rhs.data_[i];
	}
	delete[] data_;
	size_ = rhs.size_;
	i_top_ = rhs.i_top_;
	data_ = ndata;
	return *this;
}

QueueArr::QueueArr(QueueArr&& other) {
	data_ = other.data_;
	size_ = other.size_;
	i_top_ = other.i_top_;
	other.data_ = nullptr;
	other.size_ = 0;
	other.i_top_ = -1;
}

QueueArr& QueueArr::operator=(QueueArr&& other) {
	if (this != &other) {
		delete[] data_;
		data_ = other.data_;
		size_ = other.size_;
		i_top_ = other.i_top_;
		other.data_ = nullptr;
		other.size_ = 0;
		other.i_top_ = -1;
	}
	return *this;
}