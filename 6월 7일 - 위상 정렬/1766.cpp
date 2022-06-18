#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> topologicalSort(int n, vector<vector<int>>& graph, vector<int>& indegree) {
	priority_queue<int, vector<int>, greater<>> pq; //문제 번호가 낮을수록 쉬운문제이므로
	vector<int> result;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) pq.push(i);
	}
	while (!pq.empty()) {
		int current = pq.top();
		pq.pop();
		result.push_back(current);
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				pq.push(next);
			}
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> indegree(n + 1);
	vector<vector<int>> graph(n + 1, vector<int>(0));
	vector<int> result(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	result= topologicalSort(n, graph, indegree);
	for (int i = 0; i <n; i++) {
		cout << result[i] << " ";
	}
}
