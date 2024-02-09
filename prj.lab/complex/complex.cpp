#include "complex.hpp"

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
	std::istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		std::cout << "Read success: " << str << " -> " << z << "\n";
	}
	else {
		std::cout << "Read error: " << str << " -> " << z << "\n";
	}
	return istrm.good();
}

Complex& Complex::operator=(const double rhs) {
	re = rhs;
	im = 0.0;
	return *this;
}

Complex& Complex::operator/=(const double rhs) {
	return operator/=(Complex(rhs)); 
}

Complex& Complex::operator*=(const double rhs) { 
	return operator*=(Complex(rhs)); 
}

Complex& Complex::operator-=(const double rhs) { 
	return operator-=(Complex(rhs)); 
}

Complex& Complex::operator+=(const double rhs) {
	return operator+=(Complex(rhs)); 
}

Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	double k, e;
	k = re;
	e = im;
	re *= rhs.re;
	im *= rhs.im;
	re -= im;
	im = k * rhs.im + e * rhs.re;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	double k;
	k = re;
	if ((rhs.im * rhs.im + rhs.re * rhs.re) != 0) {
		re = (re * rhs.re + im * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
		im = (im * rhs.re - k * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
		return *this;
	}
	throw std::invalid_argument("Division by zero");
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator+(const Complex& lhs, const double rhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator+(const double lhs, const Complex& rhs)
{
	Complex sum(rhs);
	sum += lhs;
	return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex minus(lhs);
	minus -= rhs;
	return minus;
}

Complex operator-(const Complex& lhs, const double rhs)
{
	Complex minus(lhs);
	minus -= rhs;
	return minus;
}

Complex operator-(const double lhs, const Complex& rhs)
{
	Complex minus(rhs);
	minus -= lhs;
	minus *= -1;
	return minus;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex umn(lhs);
	umn *= rhs;
	return umn;
}

Complex operator*(const Complex& lhs, const double rhs)
{
	Complex umn(lhs);
	umn *= rhs;
	return umn;
}

Complex operator*(const double lhs, const Complex& rhs)
{
	Complex umn(rhs);
	umn *= lhs;
	return umn;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex raz(lhs);
	raz /= rhs;
	return raz;
}

Complex operator/(const Complex& lhs, const double rhs)
{
	Complex raz(lhs);
	raz /= rhs;
	return raz;
}

Complex operator/(const double lhs, const Complex& rhs)
{
	Complex raz(lhs);
	raz /= rhs;
	return raz;
}

bool operator==(const Complex& lhs, const double rhs) 
{
	if (lhs.im == 0 && std::abs(lhs.re - rhs) < eps) {
		return true;
	}
	return false;
}

bool operator==(const double lhs, const Complex& rhs)
{
	if (rhs.im == 0 && std::abs(rhs.re - lhs) < eps) {
		return true;
	}
	return false;
}

bool operator!=(const Complex& lhs, const double rhs)
{
	return !(lhs == rhs);
}

bool operator!=(const double lhs, const Complex& rhs)
{
	return !(lhs == rhs);
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}