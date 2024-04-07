#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "rational/rational.hpp"
#include "doctest.h" 

TEST_CASE("rational ctor") {
	Rational r_def;
	CHECK(0 == r_def.num());
	CHECK(1 == r_def.den());

	Rational r_int(3);
	CHECK(3 == r_int.num());
	CHECK(1 == r_int.den());

	CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("=") {
	CHECK(Rational(2, 1) == (Rational(4, 3) = std::int64_t(2)));
	CHECK(Rational(5, 3) == (Rational(9, 7) = Rational(10, 6)));
}

TEST_CASE("+") {
	CHECK(Rational(41, 21) == (Rational(2, 7) + Rational(5, 3)));
	CHECK(Rational(22, 1) == (Rational(11, 2) + Rational(33, 2)));
	CHECK(Rational(10, 3) == (Rational(4, 3) += Rational(2, 1)));
	CHECK(Rational(11, 3) == (Rational(2, 3) += std::int64_t(3)));
	CHECK(Rational(7, 2) == (Rational(9, 6) + std::int64_t(2)));
}

TEST_CASE("-") {
	CHECK(Rational(1, 1) == (Rational(3, 2) -= Rational(1, 2)));
	CHECK(Rational(17, 12) == (Rational(8, 3) -= Rational(5, 4)));
	CHECK(Rational(-9, 20) == (Rational(4, 5) - Rational(5, 4)));
	CHECK(Rational(-1, 9) == (Rational(8, 9) - std::int64_t(1)));
	CHECK(Rational(1, 9) == (std::int64_t(1) - Rational(8, 9)));
	CHECK(Rational(-2, 1) == (Rational(4, 2) -= std::int64_t(4)));
}

TEST_CASE("*") {
	CHECK(Rational(11, 5) == (Rational(2, 5) *= Rational(11, 2)));
	CHECK(Rational(13, 12) == (Rational(13, 4) * Rational(1, 3)));
	CHECK(Rational(1, 1) == (Rational(7, 21) * std::int64_t(3)));
	CHECK(Rational() == (std::int64_t(0) * Rational(9, 6)));
}

TEST_CASE("/") {
	CHECK(Rational(4, 55) == (Rational(2, 5) /= Rational(11, 2)));
	CHECK(Rational(25, 16) == (Rational(5, 2) / Rational(8, 5)));
	CHECK(Rational(11, 20) == (Rational(11, 2) / std::int64_t(10)));
	CHECK(Rational(20, 11) == (std::int64_t(10) / Rational(11, 2)));
	CHECK(Rational() == (std::int64_t(0) / Rational(4, 6)));
	CHECK_THROWS(Rational(4, 6) / std::int64_t(0));
}

TEST_CASE("unarminus") {
	CHECK(Rational(-33, 6) == (-Rational(11, 2)));
}

TEST_CASE("cut_back") {
	CHECK(Rational(-1, 20) == Rational(-5, 100));
	CHECK(Rational(4, 1) == Rational(64, 16));
}

TEST_CASE("minus") {
	CHECK(Rational(-3, 1) == Rational(3, -1));
	CHECK(Rational(3, 1) == Rational(-3, -1));
}

TEST_CASE("num_den") {
	CHECK(std::int64_t(4) == (Rational(4, 3).get_Num()));
	CHECK(std::int64_t(3) == (Rational(4, 3).get_Den()));
}

TEST_CASE("equality") {
	CHECK(Rational(12, 13) == Rational(24, 26));
	CHECK(Rational(8, 2) == std::int64_t(4));
	CHECK(Rational(86, 58) != Rational(87, 58));
	CHECK(std::int64_t(3) != Rational(3, 9));
	CHECK(Rational() == Rational(0));
}

TEST_CASE("more") {
	CHECK(Rational(13, 5) > Rational(10, 4));
	CHECK(Rational(7, 2) > std::int64_t(3));
	CHECK(Rational(33, 4) >= Rational(66, 8));
	CHECK(std::int64_t(2) >= Rational(82, 41));
}

TEST_CASE("less") {
	CHECK(Rational(19, 2) < Rational(10, 1));
	CHECK(Rational(11, 3) < std::int64_t(4));
	CHECK(Rational(4, 5) <= Rational(5, 4));
	CHECK(std::int64_t(17) <= Rational(187, 11));
}


/*int main() {
	Rational x, y;
	int64_t a;

	// сложениe для двух рациональных 1
	x = Rational(2, 7);
	y = Rational(5, 3);
	std::cout << x + y << std::endl;

	// сложениe двух рациональных чисел с одинаковыми знаменателями 2
	x = Rational(11, 2);
	y = Rational(33, 2);
	std::cout << x + y << std::endl;

	// сложениe с присваиванием для двух рациональных 3
	x = Rational(4, 3);
	y = Rational(2, 1);
	x += y;
	std::cout << x << std::endl;

	// сложениe с присваиванием для рационального и целого 4
	x = Rational(2, 3);
	a = 3;
	x += a;
	std::cout << x << std::endl;

	// сложениe рационального и целого 5
	x = Rational(9, 6);
	a = 2;
	std::cout << x + a << " " << a + x << std::endl;

	// разность с присваиванием для двух рациональных c одинаковыми знаменателями 6
	x = Rational(3, 2);
	y = Rational(1, 2);
	x -= y;
	std::cout << x << std::endl;

	// разность с присваиванием для двух рациональных 7
	x = Rational(8, 3);
	y = Rational(5, 4);
	x -= y;
	std::cout << x << std::endl;

	// разность двух рациональных 8
	x = Rational(4, 5);
	y = Rational(5, 4);
	std::cout << x - y << std::endl;

	// разность рационального и целого 9
	x = Rational(8, 9);
	a = 1;
	std::cout << x - a << " " << a - x << std::endl;

	// произведение с присваиванием для двух рациональных 10
	x = Rational(2, 5);
	y = Rational(11, 2);
	x *= y;
	std::cout << x << std::endl;

	// произведение двух рациональных 11
	x = Rational(13, 4);
	y = Rational(1, 3);
	std::cout << x * y << std::endl;

	// произведение для рационального и целого 12
	x = Rational(7, 21);
	a = 3;
	std::cout << x * a << " " << a * x << std::endl;

	// частное с присваиванием для двух рациональных 13
	x = Rational(2, 5);
	y = Rational(11, 2);
	x /= y;
	std::cout << x << std::endl;

	// частное двух рациональных 14
	x = Rational(5, 2);
	y = Rational(8, 5);
	std::cout << x / y << std::endl;

	// частное рационального и целого 15
	x = Rational(11, 2);
	a = 10;
	std::cout << x / a << " " << a / x << std::endl;

	// присваивание целой переменной к рациональной 16
	x = Rational(4, 3);
	a = 2;
	x = a;
	std::cout << x << std::endl;

	// попытка сделать рациональное число со знаменателем равным нулю 17
	try {
		Rational z(2, 0);
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	// сначало делаем только знаменатель отрицательным, а потом и знаменатель, и числитель 18
	Rational z(3, -1);
	std::cout << z << std::endl;
	Rational w(-3, -1);
	std::cout << w << std::endl;

	// сократимая дробь 19
	Rational r(-5, 100);
	std::cout << r << std::endl;
	r = Rational(64, 16);
	std::cout << r << std::endl;


	// инкремент и дикремент 20
	x = Rational(8, 5);
	std::cout << ++x << std::endl;
	std::cout << --x << std::endl;

	// получение числителя и знаменателя 21
	x = Rational(4, 3);
	std::cout << x.get_Num() << " " << x.get_Den() << std::endl;

	// сравнение двух рациональных на равенство
	x = Rational(12, 13);
	y = Rational(24, 26);
	std::cout << std::boolalpha << std::endl;
	std::cout << (x == y) << std::endl;
	std::cout << (x != y) << std::endl;
	y = Rational(23, 26);
	std::cout << (x == y) << std::endl;
	std::cout << (x != y) << std::endl;

	// сравнение рационального и целого на равенство
	x = Rational(2, 1);
	a = 2;
	std::cout << (x == a) << " " << (a == x) << std::endl;
	std::cout << (x != a) << " " << (a != x) << std::endl;
	x = Rational(2, 3);
	std::cout << (x == a) << " " << (a == x) << std::endl;
	std::cout << (x != a) << " " << (a != x) << std::endl;

	// сравнение рациональных на > и <
	x = Rational(4, 5);
	y = Rational(7, 6);
	std::cout << (x > y) << " " << (x < y) << std::endl;

	// сравнение рациональных на >= и <=
	x = Rational(6, 3);
	y = Rational(2, 1);
	std::cout << (x >= y) << " " << (x <= y) << std::endl;

	// сравнение рационального и целого на > и <
	x = Rational(2, 3);
	a = 1;
	std::cout << (a > x) << " " << (a < x) << std::endl;

	// сравнение рационального и целого на > и <
	x = Rational(1000, 10);
	a = 100;
	std::cout << (a >= x) << " " << (x <= a) << std::endl;

	return 0;
}*/

