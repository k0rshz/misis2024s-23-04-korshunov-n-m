#include <iostream>

int main() {
	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		std::string s = "";
		const int z = 96;
		int a;
		std::cin >> a;
		for (int j = 0; j < 3; ++j) {
			int b = 1;
			int f = 0;
			while (f != 1) {
				if (a - b > 26 * (3 - j - 1)) {
					b += 1;
				}
				else {
					a -= b;
					f = 1;
				}
			}
			char c = static_cast<char>(z + b);		
			s += c;
		}
		std::cout << s << std::endl;
	}
	return 0;
}