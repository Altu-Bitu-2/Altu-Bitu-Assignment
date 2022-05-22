#include <iostream>
#include <vector>
#include<queue>
using namespace std;
vector<bool> findTree(vector<vector<int>>&tree, int n, int delete_node) {
	// 트리를 순회하면서 지워진 노드는 방문 처리
	vector<bool>visited(n, false);
	queue<int>q;
	visited[delete_node] = true;
	q.push(delete_node);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < tree[cur].size(); i++) {
			int next = tree[cur][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
	return visited;
}

int main() {
	int n, delete_node, root;
	cin >> n;
	vector<vector<int>>tree(n);
	for (int i = 0; i < n; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			root = i;
			continue;
		}
		tree[parent].push_back(i);
	}
	cin >> delete_node;
	vector<bool>visited = findTree(tree, n, delete_node);
	int answer = 0;
	for (int i = 0; i < n; i++) {
		//지워진 자식 노드 수
		int cnt = 0;
		for (int j = 0; j < tree[i].size(); j++) {
			if (visited[tree[i][j]]) cnt++;
		}
		//만약 원래 있던 자식들이 다 지워졌고(원래 자식이 0개였고), 본인은 지워지지 않았다면 리프노드
		if (cnt == tree[i].size() && !visited[i]) answer++;
	}
	cout << answer;
}
