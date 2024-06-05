#include "rational.hpp"

Rational::Rational()
    : num_{ 0 }
    , den_{ 1 }
{
}

Rational::Rational(std::int64_t num, std::int64_t den)
    : num_{ num }
    , den_{ den }
{
    if (den == 0) {
        throw std::invalid_argument("Denominator should be greater than zero!\n");
    }
    else {
        num_ = num;
        den_ = den;
        ChangeRational();
    }
}

std::int64_t Rational::num() const {
    return num_;
}

std::int64_t Rational::den() const {
    return den_;
}

void Rational::ChangeRational() {
    if (den_ < 0) {
        den_ = -den_;
        num_ = -num_;
    }
    std::int64_t GCD = std::gcd(std::abs(num_), std::abs(den_));
    den_ /= GCD,
        num_ /= GCD;
}

Rational& Rational::operator=(const Rational& rhs) {
    if (this != &rhs) {
        num_ = rhs.num_;
        den_ = rhs.den_;
        ChangeRational();
    }
    return *this;
}
Rational& Rational::operator=(const std::int64_t rhs) {
    return operator=(Rational(rhs, 1));
}

Rational& Rational::operator*=(const Rational& rhs) {
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    ChangeRational();
    return *this;
}
Rational& Rational::operator*=(const std::int64_t rhs) {
    return operator*=(Rational(rhs, 1));
}

Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.num_ != 0) {
        num_ *= rhs.den_;
        den_ *= rhs.num_;
        ChangeRational();
        return *this;
    }
    throw std::invalid_argument("Divide by zero exception");
}
Rational& Rational::operator/=(const std::int64_t rhs) {
    return operator/=(Rational(rhs));
}

Rational& Rational::operator+=(const Rational& rhs) {
    std::int64_t GCD = std::gcd(den_, rhs.den_);
    num_ = num_ * (rhs.den_ / GCD) + rhs.num_ * (den_ / GCD);
    den_ = den_ / GCD * rhs.den_;
    ChangeRational();
    return *this;
}
Rational& Rational::operator+=(const std::int64_t rhs) {
    return operator+=(Rational(rhs, 1));
}

Rational& Rational::operator-=(const Rational& rhs) {
    std::int64_t GCD = std::gcd(den_, rhs.den_);
    num_ = num_ * (rhs.den_ / GCD) - rhs.num_ * (den_ / GCD);
    den_ = den_ / GCD * rhs.den_;
    ChangeRational();
    return *this;
}
Rational& Rational::operator-=(const std::int64_t rhs) {
    return operator-=(Rational(rhs));
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return (lhs.num() == rhs.num() && lhs.den() == rhs.den());
}
bool operator==(const Rational& lhs, const std::int64_t rhs) {
    return lhs == Rational(rhs);
}
bool operator==(const std::int64_t lhs, const Rational& rhs) {
    return Rational(lhs) == rhs;
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}
bool operator!=(const Rational& lhs, const std::int64_t rhs) {
    return !(lhs == rhs);
}
bool operator!=(const std::int64_t lhs, const Rational& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return (lhs.num() * rhs.den() < rhs.num() * lhs.den());
}
bool operator<(const Rational& lhs, const std::int64_t rhs) {
    return (lhs < Rational(rhs));
}
bool operator<(const std::int64_t lhs, const Rational& rhs) {
    return (Rational(lhs) < rhs);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
    return (lhs.num() * rhs.den() <= rhs.num() * lhs.den());
}
bool operator<=(const Rational& lhs, const std::int64_t rhs) {
    return lhs <= Rational(rhs);
}
bool operator<=(const std::int64_t lhs, const Rational& rhs) {
    return Rational(lhs) <= rhs;
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    return (lhs.num() * rhs.den() > rhs.num() * lhs.den());
}
bool operator>(const Rational& lhs, const std::int64_t rhs) {
    return lhs > Rational(rhs);
}
bool operator>(const std::int64_t lhs, const Rational& rhs) {
    return Rational(lhs) > rhs;
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
    return (lhs.num() * rhs.den() >= rhs.num() * lhs.den());
}
bool operator>=(const Rational& lhs, const std::int64_t rhs) {
    return lhs >= Rational(rhs);
}
bool operator>=(const std::int64_t lhs, const Rational& rhs) {
    return Rational(lhs) >= rhs;
}


Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational sum = lhs;
    sum += rhs;
    return sum;
}

Rational operator+(const Rational& lhs, std::int64_t rhs) {
    Rational sum = lhs;
    sum += rhs;
    return sum;
}

Rational operator+(std::int64_t lhs, const Rational& rhs) {
    return operator+(rhs, lhs);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational dif = lhs;
    dif -= rhs;
    return dif;
}
Rational operator-(const Rational& lhs, std::int64_t rhs) {
    Rational dif = lhs;
    dif -= Rational(rhs, 1);
    return dif;
}
Rational operator-(std::int64_t lhs, const Rational& rhs) {
    return -operator-(rhs, lhs);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational product = lhs;
    product *= rhs;
    return product;
}
Rational operator*(const Rational& lhs, std::int64_t rhs) {
    Rational product = lhs;
    product *= Rational(rhs);
    return product;
}
Rational operator*(std::int64_t lhs, const Rational& rhs) {
    return operator*(Rational(lhs), rhs);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational division = lhs;
    if (rhs.num() != 0) {
        division /= rhs;
        return division;
    }
    throw std::invalid_argument("Divide by zero exception");
}
Rational operator/(const Rational& lhs, std::int64_t rhs) {
    Rational division = lhs;
    if (rhs != 0) {
        division /= Rational(rhs, 1);
        return division;
    }
    throw std::invalid_argument("Divide by zero exception");
}
Rational operator/(std::int64_t lhs, const Rational& rhs) {
    Rational division = Rational(lhs, 1);
    division /= rhs;
    return division;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
    return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) {
    return rhs.readFrom(istrm);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
    ostrm << num_ << Rational::slash << den_;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
    std::int64_t numerator;
    char division_sign;
    std::int64_t denominator;

    istrm >> numerator;
    char after_numerator = istrm.peek();

    istrm >> division_sign;
    char after_sign = istrm.peek();
    istrm >> denominator;

    bool no_spaces = (after_numerator == Rational::slash)
        && (after_sign >= '0' && after_sign <= '9');

    bool istrm_good = no_spaces &&
        (istrm.good() || (!istrm.fail() && !istrm.bad() && istrm.eof()));

    if (istrm_good) {
        if (denominator > 0 && division_sign == Rational::slash) {
            num_ = numerator;
            den_ = denominator;
            ChangeRational();
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    else (istrm.setstate(std::ios_base::failbit));
    return istrm;
}

bool testParse(const std::string& str) {
    using namespace std;
    istringstream istrm(str);
    Rational z;
    istrm >> z;

    bool istrm_good = istrm.good() || (!istrm.fail() && !istrm.bad());
    if (istrm_good) {
        cout << "Read success: " << str << endl;
    }
    else {
        cout << "Read error : " << str << endl;
    }
    return istrm_good;
}