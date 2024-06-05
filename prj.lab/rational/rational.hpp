#ifndef RATIONAL_H_20112023
#define RATIONAL_H_20112023

#include <iostream>
#include <sstream>
#include <numeric>

class Rational {
public:
	Rational();
	Rational(const Rational&) = default;
	Rational(std::int64_t num, std::int64_t den);
	Rational(std::int64_t num) : num_{ num }, den_{ 1 } {};
	~Rational() = default;

	Rational operator-() const { return Rational(-num_, den_); }

	Rational& operator=(const Rational& rhs);
	Rational& operator=(const std::int64_t rhs);

	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const std::int64_t rhs);

	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const std::int64_t rhs);

	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const std::int64_t rhs);

	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const std::int64_t rhs);

	std::int64_t num() const;
	std::int64_t den() const;
	std::istream& readFrom(std::istream& istr);
	std::ostream& writeTo(std::ostream& ostr) const;

private:
	std::int64_t num_{ 0 };
	std::int64_t den_{ 1 };
	void ChangeRational();
	static const char slash{ '/' };
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);

std::istream& operator>>(std::istream& istrm, Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, std::int64_t rhs);
Rational operator+(std::int64_t lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, std::int64_t rhs);
Rational operator-(std::int64_t lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, std::int64_t rhs);
Rational operator*(std::int64_t lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, std::int64_t rhs);
Rational operator/(std::int64_t lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const Rational& rhs);
bool operator==(const std::int64_t lhs, const Rational& rhs);
bool operator==(const Rational& lhs, const std::int64_t rhs);

bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const std::int64_t rhs);
bool operator!=(const std::int64_t lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const std::int64_t rhs);
bool operator<(const std::int64_t lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const std::int64_t rhs);
bool operator>(const std::int64_t lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const std::int64_t rhs);
bool operator<=(const std::int64_t lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const std::int64_t rhs);
bool operator>=(const std::int64_t lhs, const Rational& rhs);

bool testParse(const std::string& str);

#endif