#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int shark = 2;
tuple<int, int, int> bfs(vector<vector<int>>& v, int n, int x, int y) {
	vector<vector<int>>visited(n, vector<int>(n, -1));
	vector <tuple<int, int, int>>fish;
	queue<pair<int, int>>q;

	visited[x][y] = 1;
	q.push({ x,y });

	while (!q.empty()) {
		int current_x = q.front().first;
		int current_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = current_x + dx[i];
			int next_y = current_y + dy[i];

			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;
			if (visited[next_x][next_y] != -1 || v[next_x][next_y] > shark) continue;



			//물고기가 있는 경우
			if (v[next_x][next_y] > 0 && v[next_x][next_y] < shark) {
				fish.push_back({ visited[current_x][current_y], next_x, next_y });
			}

			visited[next_x][next_y] = visited[current_x][current_y] + 1;
			q.push({ next_x, next_y });

		}
	}

	sort(fish.begin(), fish.end());

	//더이상 물고기를 먹을 수 없음
	if (fish.size() == 0) return { -1, -1, -1 };

	int min_dist = get<0>(fish[0]);
	int min_x = get<1>(fish[0]);
	int min_y = get<2>(fish[0]);

	return { min_dist, min_x, min_y };

}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	int start_x = 0; int start_y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 9) {
				start_x = i;
				start_y = j;
				v[i][j] = 0;
			}
		}
	}

	int t = 0;
	int eat = 0;

	while (true) {
		tuple<int, int, int> ti = bfs(v, n, start_x, start_y);

		int dist = get<0>(ti);
		int x = get<1>(ti);
		int y = get<2>(ti);

		if (dist == -1 && x == -1 && y == -1) break;

		t += dist;
		v[x][y] = 0;
		start_x = x;
		start_y = y;
		eat++;
		if (eat == shark) {
			shark++;
			eat = 0;
		}
	}
	cout << t;
}