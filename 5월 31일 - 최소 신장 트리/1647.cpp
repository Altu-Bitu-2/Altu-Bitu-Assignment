#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
int prim(int n, vector<vector<pi>>& graph) {
	priority_queue<pi, vector<pi>, greater<>> pq;
	vector<bool> visited(n + 1, false);
	
	pq.push({ 0, 1 });

	int cnt = 0;
	int sum = 0;
	int max_cost = 0;

	while (!pq.empty()) {
		auto [cur_cost, cur] = pq.top();
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		sum += cur_cost;
		//최대 간선
		max_cost = max(max_cost, cur_cost);

		for (auto [next_cost, next] : graph[cur]) {
			if (!visited[next]) {
				pq.push({ next_cost, next });
			}
		}
	}
	return sum-max_cost;
}
int main() {
	//MST를 만들고 최대 간선을 삭제하면 됨
	int n, m;
	cin >> n >> m;
	vector<vector<pi>> graph(n + 1, vector<pi>(0));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}
	cout << prim(n, graph);
}
