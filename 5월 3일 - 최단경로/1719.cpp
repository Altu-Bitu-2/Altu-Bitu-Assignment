#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
const int INF = 1e9;
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	//dist: 걸리는 시간, answer: 최초 방문 노드
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	vector<vector<int>> answer(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		dist[a][b] = t;
		dist[b][a] = t;

		answer[a][b] = b;
		answer[b][a] = a;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				//i->j로 이동할 때 k를 거쳐 간다면 i->j로 가는 곳은 k가 최초 노드가 됨
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					answer[i][j] = answer[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i==j) cout << "- ";
			else cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}
