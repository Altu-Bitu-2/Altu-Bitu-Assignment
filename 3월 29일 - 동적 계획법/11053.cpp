#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> dp(N+1,1);
	vector<int> A(N+1);
	int answer = 1;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(answer, dp[i]);
	}
	cout << answer;
}
