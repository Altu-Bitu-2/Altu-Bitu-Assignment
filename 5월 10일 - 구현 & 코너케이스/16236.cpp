#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0 };
queue<pair<int, int>>q;
vector <tuple<int, int, int>>fish;
int shark = 2;

pair<int,int> bfs(vector<vector<int>> &v, vector<vector<int>> &visited, int n, int x, int y) {
	visited[x][y] = 1;
	q.push({ x,y });

	while (!q.empty()) {
		int current_x = q.front().first;
		int current_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;
			if (visited[next_x][next_y] != -1 || v[next_x][next_y] > shark) continue;

			//물고기가 있는 경우
			if (v[next_x][next_y] > 0 && v[next_x][next_y] < shark) {
				fish.push_back({ visited[next_x][next_y], next_x, next_y });
			}

			visited[next_x][next_y] = visited[x][y] + 1;
			q.push({next_x, next_y});
			
		}
	}
	
	sort(fish.begin(), fish.end());
	if (fish.size() == 0) return { -1, -1 };

	int min_dist = get<0>(fish[0]);
	int min_x = get<1>(fish[0]);
	int min_y = get<2>(fish[0]);

	return { min_x, min_y };

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
		vector<vector<int>>visited(n, vector<int>(n, -1));
		pair<int, int> p = bfs(v, visited, n, start_x, start_y);
		cout << p.first << p.second;
		if (p.first == -1 && p.second == -1) break;
		t += visited[p.first][p.second];
		v[p.first][p.second] = 0;
		start_x = p.first;
		start_y = p.second;
		eat++;
		if (eat == shark) {
			shark++;
			eat = 0;
		}
	}
	cout << t;
}
