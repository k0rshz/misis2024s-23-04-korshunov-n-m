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
	std::cout << "\n";
	a.multi(0.1);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << a.at(i, j) << " ";
		}
		std::cout << "\n";
	}
	return 0;
}