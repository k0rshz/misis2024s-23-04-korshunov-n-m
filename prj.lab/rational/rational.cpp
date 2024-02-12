#include "rational.hpp"

Rational::Rational(const std::int64_t num, const std::int64_t denum)
	: num_(num), den_(denum) {
	if (0 == den_) {
		throw std::overflow_error("Error: Division by zero");
	}
	if (den_ < 0) {
		den_ = -denum;
		num_ = -num;
	}
	else if (num_ == 0) {
		num_ = num;
		den_ = 1;
	}
	else {
		num_ = num;
		den_ = denum;
	}
	cut_back();
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

std::int64_t Rational::NOK(std::int64_t x, std::int64_t y) {
	std::int64_t z = 2;
	while (z % x != 0 || z % y != 0) {
		z++;
	}
	return z;
}

std::int64_t Rational::NOD(std::int64_t x, std::int64_t y) {
	if (x != 0 && y != 0) {
		std::int64_t z = std::min(std::abs(x), y);
		while (std::abs(x) % z != 0 || y % z != 0) {
			z--;
		}
		return z;
	}
	return 0;
}

void Rational::cut_back() {
	std::int64_t d = Rational::NOD(num_, den_);
	if (d != 0) {
		num_ /= d;
		den_ /= d;
	}
}

Rational& Rational::operator+=(const Rational& rhs) {
	if (den_ == rhs.den_) {
		num_ += rhs.num_;
	}
	else {
		std::int64_t a = Rational::NOK(den_, rhs.den_);
		num_ = num_ * a / den_ + rhs.num_ * a / rhs.den_;
		den_ = a;
	}
	cut_back();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
	num_ *= rhs.num_;
	den_ *= rhs.den_;
	cut_back();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
	num_ *= rhs.den_;
	den_ *= rhs.num_;
	cut_back();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
	if (den_ == rhs.den_) {
		num_ -= rhs.num_;
	}
	else {
		std::int64_t a = Rational::NOK(den_, rhs.den_);
		num_ = num_ * a / den_ - rhs.num_ * a / rhs.den_;
		den_ = a;
	}
	cut_back();
	return *this;
}

Rational& Rational::operator-() {
	num_ *= -1;
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator+(const Rational& lhs, const std::int64_t& rhs) {
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator+(const std::int64_t& lhs, const Rational& rhs) {
	Rational sum(rhs);
	sum += lhs;
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational minus(lhs);
	minus -= rhs;
	return minus;
}

Rational operator-(const Rational& lhs, const std::int64_t& rhs) {
	Rational minus(lhs);
	minus -= rhs;
	return minus;
}

Rational operator-(const std::int64_t& lhs, const Rational& rhs) {
	Rational minus(rhs);
	minus -= lhs;
	minus *= -1;
	return minus;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational umn(lhs);
	umn *= rhs;
	return umn;
}

Rational operator*(const Rational& lhs, const std::int64_t& rhs) {
	Rational umn(lhs);
	umn *= rhs;
	return umn;
}

Rational operator*(const std::int64_t& lhs, const Rational& rhs) {
	Rational umn(rhs);
	umn *= lhs;
	return umn;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational del(lhs);
	if (rhs.get_Num() != 0) {
		del /= rhs;
		return del;
	}
	throw std::overflow_error("Error: Division by zero");
}

Rational operator/(const Rational& lhs, const std::int64_t& rhs) {
	Rational del(lhs);
	if (rhs != 0) {
		del /= rhs;
		return del;
	}
	throw std::overflow_error("Error: Division by zero");
}

Rational operator/(const std::int64_t& lhs, const Rational& rhs) {
	Rational del(1, 1);
	if (rhs.get_Num() != 0) {
		del /= rhs;
		del *= lhs;
		return del;
	}
	throw std::overflow_error("Error: Division by zero");
}

bool operator==(const Rational& lhs, const std::int64_t& rhs) {
	if (lhs.get_Num() == rhs && lhs.get_Den() == 1) {
		return true;
	}
	return false;
}

bool operator==(const std::int64_t& lhs, const Rational& rhs) {
	if (rhs.get_Num() == lhs && rhs.get_Den() == 1) {
		return true;
	}
	return false;
}

bool operator!=(const Rational& lhs, const std::int64_t& rhs) {
	if (lhs.get_Num() == rhs && lhs.get_Den() == 1) {
		return false;
	}
	return true;
}

bool operator!=(const std::int64_t& lhs, const Rational& rhs) {
	if (rhs.get_Num() == lhs && rhs.get_Den() == 1) {
		return false;
	}
	return true;
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() >= 0);
}

bool operator>=(const Rational& lhs, const std::int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() >= 0);
}

bool operator>=(const std::int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.get_Num() >= 0);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() <= 0);
}

bool operator<=(const Rational& lhs, const std::int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() <= 0);
}

bool operator<=(const std::int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.get_Num() <= 0);
}

bool operator>(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() > 0);
}

bool operator>(const Rational& lhs, const std::int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() > 0);
}

bool operator>(const std::int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.get_Num() > 0);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() < 0);
}

bool operator<(const Rational& lhs, const std::int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.get_Num() < 0);
}

bool operator<(const std::int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.get_Num() < 0);
}

bool testParse(const std::string& str) {
	std::istringstream istrm(str);
	Rational z;
	istrm >> z;
	if ((istrm.good()) || (!istrm.fail() && !istrm.bad() && istrm.eofbit)) {
		std::cout << "Read success: " << str << " -> " << z << "\n";
	}
	else {
		std::cout << "Read error: " << str << " -> " << z << "\n";
	}
	return istrm.good();
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << num_ << '/' << den_;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
	int64_t num(0);
	char sep(0);
	int64_t den(1);
	istrm >> num;
	istrm.get(sep);
	int64_t a = istrm.peek();
	istrm >> den;
	if (!istrm || a > '9' || a < '0') {
		istrm.setstate(std::ios_base::failbit);
		return istrm;
	}
	if (istrm.good() || istrm.eof()) {
		if (sep == '/' && den > 0) {
			num_ = num;
			den_ = den;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}