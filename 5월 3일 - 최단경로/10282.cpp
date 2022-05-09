#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
const int INF = 1e8;
pi dijkstra(vector<vector<pi>>& v, int n, int start) {
	vector<int> dist(n + 1, INF);
	priority_queue<pi, vector<pi>, greater<>> pq;
	//감염 시간, 감염 노드
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cur_time = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		//node가 감염되면 node에 연결된 컴퓨터들 감염
		for (int i = 0; i < v[node].size(); i++) {
			int next_node = v[node][i].first;
			int inf_time = v[node][i].second + cur_time;
			if (dist[next_node] > inf_time) {
				dist[next_node] = inf_time;
				pq.push({ inf_time, next_node });
			}
		}
	}
	int cnt = 0;
	int t = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			cnt++;
			t = max(t, dist[i]);
		}
	}
	return { cnt, t };
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		//컴퓨터 수, 의존성 개수, 해킹당한 컴퓨터 번호
		int n, d, c;
		cin >> n >> d >> c;
		vector<vector<pi>> v(n + 1);
		while (d--) {
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({ a,s });
		}
		cout << dijkstra(v, n, c).first << " " << dijkstra(v, n, c).second << "\n";
	}

}
