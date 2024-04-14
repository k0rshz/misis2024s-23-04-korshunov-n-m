#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n % 2 == 1) {
            std::cout << "NO" << '\n';
            continue;
        }
        std::cout << "YES" << '\n';
        for (int i = 0; i < n / 2; ++i)
            for (int j = 0; j < 2; ++j)
                std::cout << "AB"[i & 1];
        std::cout << '\n';
    }
}