#include <iostream>

int main() {
	int t;
	std::cin >> t;
	double a;
	int n, m, k;
	for (int i = 0; i < t; ++i) {
		std::cin >> n >> m >> k;
		a = (n + m - 1) / m;
		if (a + k >= n) {
			std::cout << "NO" << "\n";
		}
		else {
			std::cout << "YEs" << "\n";
		}
	}

	return 0;
}