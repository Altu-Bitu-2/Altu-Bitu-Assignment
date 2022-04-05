#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int>coin(N);
		for (int i = 0; i < N; i++) {
			cin >> coin[i];
		}
		int money;
		cin >> money;
		vector<int>dp(money + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= money; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[money] << "\n";
	}
}
