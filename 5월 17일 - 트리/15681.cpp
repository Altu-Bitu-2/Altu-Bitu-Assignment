#include <iostream>
#include <vector>
using namespace std;
vector<int>dp(100001, 1);
int dfs(vector<bool>&visited, vector<vector<int>>&v,int current) {
	visited[current] = true;
	for (int i = 0; i < v[current].size(); i++) {
		int next = v[current][i];
		if (visited[next]) continue;
		//하위 트리들의 노드개수 더함
		dp[current] += dfs(visited, v, next);
	}
	return dp[current];
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n, r, q;
	cin >> n >> r >> q;
	vector<vector<int>> v(n+1);
	vector<bool>visited(n+1, false);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(visited, v, r);
	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		cout << dp[query] << "\n";
	}

}
