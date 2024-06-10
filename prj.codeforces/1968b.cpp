#include<iostream>
#include<vector>

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<char>a(n + 1), b(m + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= m; i++) {
			std::cin >> b[i];
		}
		std::vector<int>dp(m + 1);
		dp[1] = (a[1] == b[1] ? 1 : 0);
		for (int i = 2; i <= m; i++) {
			if (dp[i - 1] != n && b[i] == a[dp[i - 1] + 1]) {
				dp[i] = dp[i - 1] + 1;
			}
			else {
				dp[i] = dp[i - 1];
			}
		}
		std::cout << dp[m] << "\n";
	}
}