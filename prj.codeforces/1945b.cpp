#include <iostream>

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		long long int a, b, m;
		std::cin >> a >> b >> m;
		long long int c = m / a + m / b + 2;
		std::cout << c << "\n";
	}
}