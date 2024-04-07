#include "matrix/matrix.hpp"

int main() {
	Matrix a(3, 3);
	double k = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			k += 0.1;
			a.at(i, j) = k;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << a.at(i, j) << " ";
		}
		std::cout << "\n";
	}
	a.multi(0.1);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << a.at(i, j) << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	a.transpose();
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << a.at(i, j) << " ";
		}
		std::cout << "\n";
	}

	k = 0;
	Matrix c(2, 2);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			k += 1;
			c.at(i, j) = k;
		}
	}
	std::cout << "\n";
	std::cout << c.determinant();
	std::cout << "\n" << "\n";

	Matrix b(3, 2);
	k = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			k += 0.1;
			b.at(i, j) = k;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			std::cout << b.at(i, j) << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	b.multi(0.1);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			std::cout << b.at(i, j) << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	b.transpose();
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << b.at(i, j) << " ";
		}
		std::cout << "\n";
	}
	return 0;
}