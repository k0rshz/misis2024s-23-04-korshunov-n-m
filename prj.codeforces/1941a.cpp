#include <iostream>
#include <vector>

int main() {
	int t;
	std::cin >> t;
	while (t > 0) {
		int n, m, k;
		std::cin >> n >> m >> k;
		int a = 0;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> v[i];
		}
		int o;
		for (int j = 0; j < m; ++j) {
			std::cin >> o;
			for (int i = 0; i < n; i++) {
				if ((o + v[i]) <= k) {
					a += 1;
				}
			}
		}
		std::cout << a << "\n";
		t -= 1;
	}
	return 0;
}