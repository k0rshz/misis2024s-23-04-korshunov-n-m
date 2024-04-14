#include <iostream>

int main() {
    int t; 
    std::cin >> t;
    while (t--) {
        int n, k; 
        std::cin >> n >> k;
        if (k >= n - 1) {
            std::cout << 1 << "\n";
        }
        else {
            std::cout << n << "\n";
        }
    }
    return 0;
}