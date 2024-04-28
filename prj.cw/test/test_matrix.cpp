#include "matrix\matrix.hpp"

int main() {
	Matrix a(3, 3);
	double k = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			k += 0.1;
			a.at(i, j) = k;
		}
	}
	a.print();
	a.multi(0.1);
	a.print();
	std::cout << a.determinant() << "\n" << "\n"; // проверить это место
	std::cout << a.rank() << "\n" << "\n";
	a.transpose();
	a.print();
	std::cout << a.rank() << "\n" << "\n";

	k = 0;
	Matrix c(2, 2);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			k += 1;
			c.at(i, j) = k;
		}
	}
	c.print();
	std::cout << c.determinant();
	std::cout << "\n" << "\n";
	
	Matrix d(c.degree(2));
	d.print();

	c.inverse();
	c.print();

	Matrix b(3, 2);
	k = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			k += 0.1;
			b.at(i, j) = k;
		}
	}
	b.print();
	b.multi(0.1);
	b.print();
	b.transpose();
	b.print();
	b.swapRows(0, 1);
	b.print();
	std::cout << b.rank() << "\n";

	return 0;
}