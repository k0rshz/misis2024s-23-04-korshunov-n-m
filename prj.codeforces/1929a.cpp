#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int a;
		std::cin >> a;
		std::vector <int> s;
		for (int j = 0; j < a; ++j) {
			int b;
			std::cin >> b;
			s.push_back(b);
		}
		std::sort(s.begin(), s.end());
		int n = 0;
		for (int j = 1; j < a; ++j) {
			n += s[j] - s[j - 1];
		}
		std::cout << n << std::endl;
	}
	return 0;
}