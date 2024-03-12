#include <iostream>

int main() {
	int n;
	std::cin >> n;
	std::string s = "";
	int ko = 0, kl = 0, flag = 0;
	for (int i = 0; i < n; ++i) {
		char s1;
		std::cin >> s1;
		s += s1;
		if (s1 == 'O') {
			ko += 1;
		}
		else {
			kl += 1;
		}
	}
	int kos = 0, kls = 0, k = 0;
	for (int i = 0; i < n; ++i) {
		k += 1;
		if (s[i] == 'O') {
			kos += 1;
		}
		else {
			kls += 1;
		}
		if ((ko - kos != kos && kl - kls != kls) && ((kl - kls > 0) || (ko - kos > 0))) {
			std::cout << k;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		std::cout << -1;
	}
	return 0;
}