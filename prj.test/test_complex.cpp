#include "complex/complex.hpp"

int main() {

	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	std::cout << "\n";

	Complex x, y;
	double d;

	// сумма двух комплексных
	x = Complex{ 1.5, 2.0 };
	y = Complex{ 2.5, 3.5 };
	std::cout << x << " + " << y << " == " << x + y << " Expected: {4.0, 5.5}\n";
	std::cout << std::endl;

	// разность двух комплексных
	x = Complex{ 3.0, 5.0 };
	y = Complex{ 1.5, 2.5 };
	std::cout << x << " - " << y << " == " << x - y << " Expected: {1.5, 2.5}\n";
	std::cout << std::endl;

	// произведение двух комплексных
	x = Complex{ 1.5, 2.0 };
	y = Complex{ 2.0, 3.0 };
	std::cout << x << " * " << y << " == " << x * y << " Expected: {-3,8.5}\n";
	std::cout << std::endl;

	// частное двух комплексных
	x = Complex{ 3.0, 5.0 };
	y = Complex{ 1.5, 2.5 };
	std::cout << x << " / " << y << " == " << x / y << " Expected: {2, 0}\n";
	std::cout << std::endl;

	// сумма вещественного и комплексного
	d = 2.5;
	x = Complex{ 1.5, 1.0 };
	std::cout << d << " + " << x << " == " << d + x << " Expected: {4.0, 1.0}\n";
	std::cout << std::endl;

	// разность вещественного и комплексного
	d = 4.5;
	x = Complex{ 12, 35 };
	std::cout << d << " - " << x << " == " << d - x << " Expected: {-7.5, -35}\n";
	std::cout << std::endl;

	// разность комплексного и вещественного
	x = Complex{ 3.0, -2.0 };
	d = 1.5;
	std::cout << x << " - " << d << " == " << x - d << " Expected: {1.5, -2}\n";
	std::cout << std::endl;

	// произведение вещественного и комплексного
	d = 2.0;
	x = Complex{ 1.5, -1.0 };
	std::cout << d << " * " << x << " == " << d * x << " Expected: {3.0, -2.0}\n";
	std::cout << std::endl;

	// частное вещественного и комплексного
	d = 4.0;
	x = Complex{ 2.0, -1.0 };
	std::cout << d << " / " << x << " == " << d / x << " Expected: {1.6, 0.8}\n";
	std::cout << std::endl;

	// частное комплексного и вещественного
	x = Complex{ -4.0, 5.5 };
	d = 2.5;
	std::cout << x << " / " << d << " == " << x / d << " Expected: {-1.6, 2.2}\n";
	std::cout << std::endl;

	// присваивание комплексному вещественного, а потом комплексному
	d = 43.23;
	x = Complex{ 1, 1 };
	y = Complex{ 12, 33 };
	x = d;
	std::cout << x << " Expected: {43.23,0}\n";
	x = y;
	std::cout << x << " Expected: {12, 33}\n";
	std::cout << std::endl;

	// деление с присваиванием для двух комплексных
	x = Complex{ 11.1, 9.8 };
	y = Complex{ 7, -9 };
	x /= y;
	std::cout << x << " Expected: {-0.0807,1.2961}\n";
	std::cout << std::endl;

	// деление с присваиванием комплексного и вещественного
	x = Complex{ 100, 90 };
	d = 10.0;
	x /= d;
	std::cout << x << " Expected: {10,9}\n";
	std::cout << std::endl;

	// сумма с присваиванием двух комплексных
	x = Complex{ 1.12, 2.49 };
	y = Complex{ 1.88, 2.51 };
	x += y;
	std::cout << x << " Expected: {3,5}\n";
	std::cout << std::endl;

	// разность с присваиванием двух комплексных
	x -= y;
	std::cout << x << " Expected: {1.12,2.49}\n";
	std::cout << std::endl;

	// произведение с присваиванием двух комплексных
	x *= y;
	std::cout << x << " Expected: {-4.1443,7.4924}\n";
	std::cout << std::endl;

	// сумма с присваиванием для комплексного и вещественного
	x = Complex{ 1,1 };
	d = 2.0;
	x += d;
	std::cout << x << " Expected: {3, 1}\n";
	std::cout << std::endl;

	// разность с присваиванием для комплексного и вещественного
	x -= d;
	std::cout << x << " Expected: {1,1}\n";
	std::cout << std::endl;

	// деление с присваиванием для комплексного и вещественного
	x /= d;
	std::cout << x << " Expected: {0.5,0.5}\n";
	std::cout << std::endl;

	// проверка равенства для вещественного и комплексного
	d = 12.5;
	x = Complex{ 12.5, 12.5 };
	std::cout << (d == x) << " Expected: 0\n";
	std::cout << (x == d) << " Expected: 0\n";
	std::cout << (d != x) << " Expected: 1\n";
	std::cout << (x != d) << " Expected: 1\n";
	std::cout << std::endl;

	// проверка равенства для двух комплексных
	y = Complex{ 12.5, 12.5 };
	x = Complex{ 12.5, 12.5 };
	std::cout << (y == x) << " Expected: 1\n";
	std::cout << (x == y) << " Expected: 1\n";
	std::cout << (y != x) << " Expected: 0\n";
	std::cout << (x != y) << " Expected: 0\n";
	std::cout << std::endl;

	// проверка равенства для двух комплексных
	y = Complex{ 1,1 };
	std::cout << (y == x) << " Expected: 0\n";
	std::cout << (x == y) << " Expected: 0\n";
	std::cout << (y != x) << " Expected: 1\n";
	std::cout << (x != y) << " Expected: 1\n";
	std::cout << std::endl;

	// проверка деления комплексных на ноль
	x = Complex{ 2, 1.1 };
	y = Complex{ 0, 0 };
	d = 0;
	try {
		std::cout << x / y << "\n";
	}
	catch (std::invalid_argument& e) {
		std::cout << x << " / " << y << " --> " << e.what() << "\n";
	}
	std::cout << std::endl;

	// унарный минус
	x = Complex{ 1.5, -2 };
	std::cout << -x << " Expected: {-1.5,2}\n";

	return 0;
}
