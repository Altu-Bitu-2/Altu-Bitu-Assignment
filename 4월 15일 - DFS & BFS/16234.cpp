#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
typedef vector<vector<int>> vi;
typedef vector<vector<bool>> vb;
int N, L, R;	
int cnt, total;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1,1,0,0 };
void dfs(vi&country, vb&visited, vector<pi> &v, int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
		int dist = abs(country[x][y] - country[nextX][nextY]);
		//인구차가 L이상 R이하라면 국경을 연다
		if (dist >= L && dist <= R && !visited[nextX][nextY]) {
			visited[nextX][nextY] = true;
			//국경을 합친 곳의 좌표 저장
			v.push_back({ nextX, nextY });
			//합친 국가 개수
			cnt++;
			//합친 인구수
			total += country[nextX][nextY];
			dfs(country, visited, v, nextX, nextY);
		}
	}
}
void move(vector<pi>&v, vi &country) {
	//국경을 합친 국가들의 인구를 재분배함
	for (int i = 0; i < v.size(); i++) {
		country[v[i].first][v[i].second] = total / cnt;
	}
}
int main() {
	cin >> N >> L >> R;
	vi country(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> country[i][j];
		}
	}
	int answer = 0;
	while (true) {
		bool flag = false;
		vb visited(N, vector<bool>(N, false));
		vector<pi> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				visited[i][j] = true;
				cnt = 1;
				total = country[i][j];
				v.push_back({ i, j });
				dfs(country, visited, v, i,j);
				//이동을 했다는 의미
				if (cnt >= 2) {
					flag = true;
					move(v, country);
				}
				v.clear();
			}
		}
		//더이상 인구 이동이 일어나지 않으면 break
		if (!flag) break;
		else answer++;
	}
	cout << answer;
}
