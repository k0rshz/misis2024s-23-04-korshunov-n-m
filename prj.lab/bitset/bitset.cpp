#include "bitset/bitset.hpp"

BitSet::BitSet(const std::int32_t size) {
	if (size <= 0) {
		throw std::invalid_argument("size must be greater than zero");
	}
	size_ = size;
	std::vector<uint32_t> a(size_);
	bits_ = a;
}