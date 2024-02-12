#include "dynarr.hpp"

std::ptrdiff_t DynArr::Size() const noexcept {
    return size_;
}

DynArr::DynArr(DynArr const& a)
    : size_(a.size_), capacity(a.capacity) {
    data_ = new float[capacity] {};
    for (int i = 0; i < size_; ++i) {
        data_[i] = a.data_[i];
    }
}

DynArr::DynArr(const std::ptrdiff_t sizeNew) {
    if (sizeNew <0) {
        throw std::overflow_error("Error: Size cannot be less than zero");
    }
    else if (sizeNew == 0) {
        size_ = 0;
        capacity = 0;
        data_ = nullptr;
    }
    size_ = sizeNew;
    capacity = sizeNew * 2;
    data_ = new float[2 * sizeNew] {};
}

DynArr& DynArr::operator=(DynArr const& rhs) {
    if (this != &rhs) {
        delete[] data_;
        size_ = rhs.size_;
        capacity = rhs.size_ * 2;
        data_ = new float[capacity] {};
        for (int i = 0; i < rhs.size_; ++i) {
            data_[i] = rhs.data_[i];
        }
    }
    return *this;
}

float& DynArr::operator[](const std::ptrdiff_t idx) {
    if (idx >= size_ || idx < 0) {
        throw std::out_of_range("Error: Out of range");
    }
    return *(data_ + idx);
}

const float DynArr::operator[](std::ptrdiff_t idx) const {
    if (idx >= size_ || idx < 0) {
        throw std::out_of_range("Error: Out of range");
    }
    return *(data_ + idx);
}

void DynArr::Resize(const std::ptrdiff_t sizeNew) {
    if (sizeNew <= 0) {
        throw std::overflow_error("Error: Size cannot be less than or equal to zero");
    }
    if (sizeNew > capacity) {
        capacity = sizeNew * 2;
        float* pNewData = new float[capacity] {};
        for (std::ptrdiff_t i = 0; i < this->size_; ++i) {
            pNewData[i] = data_[i];
        }
        for (std::ptrdiff_t i = this->size_; i < sizeNew; ++i) {
            pNewData[i] = 0;
        }
        data_ = pNewData;
    }
    size_ = sizeNew;
}

void DynArr::Insert(const std::ptrdiff_t index, const float& val) {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Error: Out of range");
    }
    for (std::ptrdiff_t i = size_; i > index; --i) {
        data_[i] = data_[i - 1];
    }
    size_ += 1;
    data_[index] = val;
}