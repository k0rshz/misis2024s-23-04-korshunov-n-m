#pragma once
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <sstream>	
#include <cstdint>

class Rational {
public:
	Rational() = default;
	Rational(const Rational& rhs) = default;
	~Rational() = default;
	explicit Rational(const std::int64_t num) : num_(num) { }
	Rational(const std::int64_t num, const std::int64_t denum);

	std::int64_t num() const { return num_; }
	std::int64_t den() const { return den_; }

	Rational& operator=(const Rational&) = default;
	Rational& operator=(const std::int64_t rhs) { return operator=(Rational(rhs)); }
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const std::int64_t rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const std::int64_t rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const std::int64_t rhs) { return operator*=(Rational(rhs)); }
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const std::int64_t rhs) { return operator/=(Rational(rhs)); }
	Rational& operator-();
	bool operator==(const Rational& rhs) const { return ((rhs.num_ == num_) && (rhs.den_ == den_)) || ((rhs.num_ == 0) && (num_ == 0)); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	const std::int64_t& get_Num() const { return num_; }
	const std::int64_t& get_Den() const { return den_; }

private:
	std::int64_t num_{ 0 };
	std::int64_t den_{ 1 };
	void cut_back();
	std::int64_t NOD(std::int64_t x, std::int64_t y);
	std::int64_t NOK(std::int64_t x, std::int64_t y);
};

bool testParse(const std::string& str);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const std::int64_t& rhs);
Rational operator+(const std::int64_t& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const std::int64_t& rhs);
Rational operator-(const std::int64_t& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const std::int64_t& rhs);
Rational operator*(const std::int64_t& lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const std::int64_t& rhs);
Rational operator/(const std::int64_t& lhs, const Rational& rhs);


bool operator==(const Rational& lhs, const std::int64_t& rhs);
bool operator==(const std::int64_t& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const std::int64_t& rhs);
bool operator!=(const std::int64_t& lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const std::int64_t& rhs);
bool operator>=(const std::int64_t& lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const std::int64_t& rhs);
bool operator>(const std::int64_t& lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const std::int64_t& rhs);
bool operator<=(const std::int64_t& lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const std::int64_t& rhs);
bool operator<(const std::int64_t& lhs, const Rational& rhs);

#endif

/*#pragma once
#ifndef RATIONAL_RATIONAL_HPP
#define RATIONAL_RATIONAL_HPP

#include <cstdint>
#include <iosfwd>
#include <iostream>

class Rational {
public:
	[[nodiscard]] Rational() = default;
	[[nodiscard]] Rational(const Rational&) = default;
	[[nodiscard]] explicit Rational(const std::int64_t num) noexcept : num_(num) { }
	[[nodiscard]] Rational(const std::int64_t num, const std::int64_t den);
	~Rational() = default;
	[[nodiscard]] Rational& operator=(const Rational&) = default;

	[[nodiscard]] std::int64_t num() const noexcept { return num_; }
	[[nodiscard]] std::int64_t den() const noexcept { return den_; }

	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;

	[[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }

	Rational& operator+=(const Rational& rhs) noexcept;
	Rational& operator-=(const Rational& rhs) noexcept;
	Rational& operator*=(const Rational& rhs) noexcept;
	Rational& operator/=(const Rational& rhs);

	Rational& operator+=(const std::int64_t rhs) noexcept;
	Rational& operator-=(const std::int64_t rhs) noexcept;
	Rational& operator*=(const std::int64_t rhs) noexcept;
	Rational& operator/=(const std::int64_t rhs);

	std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
	std::istream& ReadFrom(std::istream& istrm) noexcept;

	const std::int64_t& get_Num() const { return num_; }
	const std::int64_t& get_Den() const { return den_; }

private:
	std::int64_t num_ = 0;
	std::int64_t den_ = 1;
};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int64_t rhs);

[[nodiscard]] Rational operator+(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int64_t lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const std::int64_t& rhs);
bool operator==(const std::int64_t& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const std::int64_t& rhs);
bool operator!=(const std::int64_t& lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const std::int64_t& rhs);
bool operator>=(const std::int64_t& lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const std::int64_t& rhs);
bool operator>(const std::int64_t& lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const std::int64_t& rhs);
bool operator<=(const std::int64_t& lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const std::int64_t& rhs);
bool operator<(const std::int64_t& lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;

#endif*/