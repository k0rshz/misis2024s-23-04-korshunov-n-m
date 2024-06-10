#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    t += 1;
    while (--t) {
        int n;
        std::cin >> n;
        std::vector <int> a(n);
        for (int& i : a) {
            std::cin >> i;
        }
        int mini = std::max(a[0], a[1]);
        for (int i = 1; i < n - 1; ++i) {
            mini = std::min(mini, std::max(a[i], a[i + 1]));
        }
        std::cout << mini - 1 << "\n";
    }
}