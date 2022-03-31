#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 1e7;
int N;
vector<vector<int>>W;
vector<bool>visited;
void backtracking(int from, int cost, int cnt) {
	//cost가 최소값보다 커지는 순간 가지치기
	if (cost > answer) return;
	//모든 도시를 돌고 시작점까지의 길이 있을 때
	if (cnt == N && W[from][0] != 0) {
		answer = min(answer, cost + W[from][0]);
		return;
	}
	for (int to = 0; to < N; to++) {
		//갈 수 없는 도시이거나 이미 방문한 경우
		if (W[from][to] == 0 || visited[to]) continue;
		else {
			visited[to] = true;
			backtracking(to, cost + W[from][to], cnt + 1);
			visited[to] = false;
		}
	}
}
int main() {
	cin >> N;
	W.assign(N, vector<int>(N));
	visited.assign(N, false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	visited[0] = true;
	backtracking(0, 0, 1);
	cout << answer;
}
