#include <iostream>
#include <vector>

int main() {
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, k;
        std::cin >> n >> k;
        std::vector <int> p(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
            p[i] -= 1;
        }
        int bad = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] % k != i % k) {
                bad += 1;
            }
        }
        if (bad == 0)
            std::cout << 0 << "\n";
        else if (bad == 2)
            std::cout << 1 << "\n";
        else
            std::cout << -1 << "\n";
    }
    return 0;
}