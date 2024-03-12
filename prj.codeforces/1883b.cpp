#include <iostream>
#include <array>

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::array <int, 26> a{};
		int s, k;
		std::cin >> s >> k;
		for (int j = 0; j < s; ++j) {
			char b;
			std::cin >> b;
			int c = static_cast<int>(b - 97);
			a[c] += 1;
		}
		int nch = 0;
		for (int j = 0; j < 26; ++j) {
			if (a[j] % 2 != 0) {
				nch += 1;
			}
		}
		if (nch - k <= 1) {
			std::cout << "YES" << "\n";
		}
		else {
			std::cout << "NO" << "\n";
		}
	}
	
	return 0;
}