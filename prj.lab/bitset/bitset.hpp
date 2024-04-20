#pragma once 
#ifndef BITSET_HPP
#define BITSET_HPP

#include <iostream>
#include <vector>

class BitSet {
public:
	BitSet() = default;
	BitSet(const BitSet&) = default;
	BitSet(BitSet&&) = default;
	BitSet(const std::int32_t);
	BitSet& operator=(const BitSet&) = default;
	BitSet& operator=(BitSet&&) = default;
	~BitSet() = default;

	bool operator==(const BitSet& rhs) const;
	bool operator!=(const BitSet& rhs) const;
	int32_t Size() const { return size_; }
	void Resize(const int32_t size); // 0 < size
	bool Get(const int32_t idx) const;
	void Set(const int32_t idx, const bool val);
	void Fill(const bool val);

	BitSet& operator&=(const BitSet& rhs);
	BitSet& operator|=(const BitSet& rhs);
	BitSet& operator^=(const BitSet& rhs);
	BitSet operator~();

	// ? operator[](const int32_t) - what can return
	// std::ostream& WriteTxt(std::ostream&)
	// std::ostream& WriteBinary(std::ostream&)
	// std::istream& ReadTxt(std::istream&)
	// std::istream& RaadBinary(std::istream&)
private:
	std::int32_t size_ = 0;
	std::vector<uint32_t> bits_;
};

// std::ostream& operaror<<(std::ostream&, const BitSet&);
// std::istream& operaror>>(std::istream&, BitSet&);

BitSet operator&(const BitSet& lhs, const BitSet& rhs);

BitSet operator|(const BitSet& lhs, const BitSet& rhs);

BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif