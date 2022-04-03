#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	string a;
	string b;
	cin >> a; cin >> b;
	int len_a = a.length();
	int len_b = b.length();
	vector<vector<int>>dp(len_a+1, vector<int>(len_b+1, 0));
	for (int i = 1; i <= len_a; i++) {
		for (int j = 1; j <= len_b; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << dp[len_a][len_b];
}
