#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> topologicalSort(int n, vector<vector<int>>& graph, vector<int>& indegree, vector<int>& cost) {
	queue<int> q;
	vector<int> dp(n+1);
	for (int i = 1; i <= n; i++) {
		dp[i] = cost[i];
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			indegree[next]--;
			dp[next] = max(dp[next], dp[current] + cost[next]);
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	return dp;
}

int main() {
	int n;
	cin >> n;
	vector<int> indegree(n + 1);
	vector <int> cost(n + 1);
	vector<vector<int>> graph(n + 1, vector<int>(0));
	for (int i = 1; i <=n; i++) {
		cin >> cost[i];
		while (true) {
			int a;
			cin >> a;
			if (a == -1) break;
			graph[a].push_back(i);
			indegree[i]++;
		}
	}
	vector<int> dp(n + 1);
	dp=topologicalSort(n, graph, indegree, cost);
	for (int i = 1; i <=n; i++) {
		cout << dp[i] << "\n";
	}
}
