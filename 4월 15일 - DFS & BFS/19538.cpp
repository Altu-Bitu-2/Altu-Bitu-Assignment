#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> bfs(vector<vector<int>>& v, vector<int>& rumor, int N, int M) {
	vector<int> answer(N + 1, -1);
	vector<int> rest(N + 1, 0);
	queue<int> q;
	for (int i = 0; i < M; i++) {
		answer[rumor[i]] = 0;
		q.push(rumor[i]);
	}
	for (int i = 1; i <= N; i++) {
		rest[i] = (v[i].size() + 1) / 2;
	}
	while (!q.empty()) {
		int cur = q.front();
		int t = answer[cur];
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (answer[next] > -1) continue;
			rest[next]--;
			//절반 이상이 믿고 있다면 temp에 넣음
			if (!rest[next]) {
				answer[next] = t + 1;
				q.push(next);
			}
			else continue;
		}
	}
	return answer;
}

int main() {
	int N, M;
	cin >> N;
	vector<vector<int>>v(N + 1);
	for (int i = 1; i <= N; i++) {
		while (true) {
			int rel;
			cin >> rel;
			if (rel == 0) break;
			v[i].push_back(rel);
		}
	}
	cin >> M;
	//rumor은 믿은 시간을 담는 배열
	vector<int> rumor(M, 0);
	for (int i = 0; i < M; i++) {
		cin >> rumor[i];
	}
	vector<int> answer = bfs(v, rumor, N, M);
	for (int i = 1; i <= N; i++) {
		cout << answer[i] << " ";
	}
}
