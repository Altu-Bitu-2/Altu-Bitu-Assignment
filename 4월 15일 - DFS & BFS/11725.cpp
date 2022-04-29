#include <iostream>
#include <vector>
const int MAX = 100001;
using namespace std;
vector<int> parent(MAX);
vector<bool>visited;
//vector<vector<int>>로 선언하면 메모리 초과남
vector<int> v[MAX];
void dfs(int node) {
	visited[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		//루트노드부터 탐색해서 방문하지 않은 노드의 부모 갱신
		if (!visited[next]) {
			parent[next] = node;
			dfs(next);
		}
	}
}
int main() {
	int N;
	cin >> N;
	visited.assign(N + 1, false);
	for (int i = 0; i < N-1; i++) {
		int x, y;
		cin >> x >> y;
		//서로 연결시켜줌
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}

