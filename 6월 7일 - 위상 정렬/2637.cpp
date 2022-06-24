#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;	
vector<int> basic;
vector<int> topologicalSort(int n, vector<vector<pi>> &graph, vector<int> &indegree) {
	queue<int> q;
	vector<int> result(n + 1, 0);
	q.push(n);
	result[n] = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		//기본부품인지
		if (graph[current].size() == 0) {
			basic.push_back(current);
		}
		
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].first;
			int cost = graph[current][i].second;
			//current를 만드는데 next가 필요한 갯수*cost
			result[next] += result[current]*cost;
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pi>> graph(n + 1, vector<pi>(0));
	vector<int> indegree(n + 1);
	while (m--) {
		int a, b, k;
		cin >> a >> b >> k;
		//a를 만드는데 b가 k개 필요함
		graph[a].push_back({ b, k });
		indegree[b]++;
	}
	vector<int> result(n + 1);
	result = topologicalSort(n, graph, indegree);
	sort(basic.begin(), basic.end());
	for (int i = 0; i<basic.size(); i++) {
		cout << basic[i] << " " << result[basic[i]] << "\n";
	}
}
