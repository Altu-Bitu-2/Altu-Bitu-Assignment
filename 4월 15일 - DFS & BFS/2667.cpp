#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector <int>> map;
vector <vector <bool>> visited;
int N; //가로 세로 길이
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int cnt = 0;
//int house = 0;
vector <int> house;
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
			if (map[nextX][nextY] && !visited[nextX][nextY]) {
				dfs(nextX, nextY);
				cnt++;
			}
		}
	}
}
int main() {
	cin >> N;
	map.assign(N, vector<int>(N, 0));
	visited.assign(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {

			map[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visited[i][j]) {
				dfs(i, j);
				house.push_back(cnt);
				cnt = 0;
			}
		}
	}
	cout << house.size() << "\n";
	sort(house.begin(), house.end());
	for (int i = 0; i < house.size(); i++) {
		cout << house[i] + 1 << "\n";
	}
}
