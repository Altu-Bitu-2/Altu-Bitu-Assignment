#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<vector<pair<int, int>>> v(10001);
int dist = 0;
int far_node = 0;
void dfs(vector<bool>& visited, int x, int cost) {
	if (visited[x]) return;
	visited[x] = true;
	//이전에 구한것보다 더 멀면 dist와 far_node 갱신
	if (dist < cost) {
		dist = cost;
		far_node = x;
	}
	for (int i = 0; i < v[x].size(); i++) {
		dfs(visited, v[x][i].first, cost + v[x][i].second);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b, cost });
		v[b].push_back({ a, cost });
	}
	//1. 가장 먼 노드 찾기
	vector<bool>visited(n + 1, false);
	dfs(visited, 1, 0);

	//2. 거슬러 올라가면서 가장 긴 지름 찾기
	visited.assign(n + 1, false);
	dfs(visited, far_node, 0);

	cout << dist;
}
