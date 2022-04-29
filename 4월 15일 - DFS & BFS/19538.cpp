#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<int> q;
void bfs(vector<vector<int>>& v, vector<int>& rumor, vector<int>& temp) {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (rumor[v[cur][i]] > -1) continue;
			//주변인의 절반이 믿어야해서 해당 사람의 주변인중 얼마나 루머를 믿고 있는지 체크
			int cnt = 0;
			for (int j = 0; j < v[next].size(); j++) {
				if (rumor[v[next][j]] > -1) cnt++;
			}
			//절반 이상이 믿고 있다면 temp에 넣음
			if (cnt * 2 >= v[next].size()) temp.push_back(next);
			else continue;
		}
	}
}
void checkRumor(vector<int>& rumor, vector<int>& temp, int time) {
	//temp에 있던 사람들을 다 q에 넣음
	for (int i = 0; i < temp.size(); i++) {
		q.push(temp[i]);
		rumor[temp[i]] = time;
	}
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
	vector<int> rumor(N + 1, -1);
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		rumor[num] = 0;
		q.push(num);
	}
	int time = 1;
	while (true) {
		vector<int> temp;
		bfs(v, rumor, temp);
		checkRumor(rumor, temp, time);
		//새로운 루머 유포자가 없을 때 종료
		if (q.empty()) break;
		time++;
	}
	for (int i = 1; i <= N; i++) {
		cout << rumor[i] << " ";
	}
}
