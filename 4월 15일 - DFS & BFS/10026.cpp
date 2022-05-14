#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R, C;
vector<vector<char>> grid;
vector <vector<bool>> visited;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int N;
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
		//�湮���� �ʾҰ� ���� Ž���� ���� ���̶�� ���� �����̱� ������ Ž�� ���
		if (!visited[nextX][nextY] && grid[nextX][nextY] == grid[x][y]) {
			dfs(nextX, nextY);
		}
	}
}
int countArea() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	return cnt;
}
int main() {
	cin >> N;
	grid.resize(N, vector<char>(N));
	visited.assign(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	cout << countArea() << " ";
	visited.assign(N, vector<bool>(N, false));
	//���ϻ����� ����� ���� ��
	for (int i = 0; i < N; i++) {
		replace(grid[i].begin(), grid[i].end(), 'G', 'R');
	}
	cout << countArea();
}
