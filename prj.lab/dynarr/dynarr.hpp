#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <cstddef>
#include <iostream>

class DynArr {
public:
    DynArr() = default;
    DynArr(const DynArr&);
    DynArr(const std::ptrdiff_t size);
    ~DynArr() {
        delete[] data_;
    }
    [[nodiscard]] DynArr& operator=(const DynArr&);
    DynArr(DynArr&&);
    DynArr& operator=(DynArr&&);
    [[nodiscard]] std::ptrdiff_t Size() const noexcept;
    void Resize(const std::ptrdiff_t size);
    void Insert(const std::ptrdiff_t index, const float& val);
    [[nodiscard]] float& operator[](const std::ptrdiff_t idx);
    [[nodiscard]] const float operator[](const std::ptrdiff_t idx) const;
private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    float* data_ = nullptr;
};

#endif