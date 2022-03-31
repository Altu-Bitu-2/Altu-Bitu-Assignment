#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ranking;	
int N, P;
long long score;

int main() {
	cin >> N >> score >> P;
	ranking.assign(P + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> ranking[i];
	}
	//불가능한 경우: N>=P 가장 작은 점수가 score과 같거나 클 때
	if (N>=P && ranking[N]>=score) {
		cout << -1;
		return 0;
	}
	int answer = 1;
	for (int i = 1; i <= N; i++) {
		if (ranking[i] <= score) break;
		else answer++;
	}
	if (N == 0) cout << 1;
	else cout << answer;
}
