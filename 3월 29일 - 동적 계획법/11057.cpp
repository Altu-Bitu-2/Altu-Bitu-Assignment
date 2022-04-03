#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>>dp(N+1, vector<int>(10));
	//한자리수는 모두 1
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	if (N == 1) {
		cout << 10;
		return 0;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				dp[i][j] %= 10007;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += dp[N][i];
		answer %=10007;
	}
	cout << answer;
}
