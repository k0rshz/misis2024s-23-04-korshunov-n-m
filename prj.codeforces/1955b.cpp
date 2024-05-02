#include <iostream>
#include <vector>

int main() {
	int m, n, b, l, res;
	std::cin >> m;
	std::vector <int> a(100);
	for (int i = 0; i < m; ++i) {
		std::cin >> n;
		for (int j = 0; j < n; ++j) {
			std::cin >> b;
			a[j] = b;
		}
		l = -1;
		res = n;
		for (int j = 0; j < n; ++j) {
			if (a[j] != a[0]) {
				res = std::min(res, j - l - 1);
				l = j;
			}
		}
		res = std::min(res, n - l - 1);
		if (res == n) {
			std::cout << -1 << "\n";
		}
		else {
			std::cout << res << "\n";
		}
	}

	return 0;
}