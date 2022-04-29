#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;
int N, K;
vector <bool> visited;
queue <pair <int, int>> q;
int cnt = 0;
int bfs(int start) {
	visited[start] = true;
	q.push({ start, cnt });
	while (!q.empty()) {
		int current = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (current == K) return cnt;
		if (current + 1 < MAX && !visited[current + 1]) {
			q.push({ current + 1, cnt + 1 });
			visited[current + 1] = true;
		}
		if (current - 1 >= 0 && !visited[current - 1]) {
			q.push({ current - 1, cnt + 1 });
			visited[current - 1] = true;
		}
		if (current * 2 < MAX && !visited[current * 2]) {
			q.push({ current * 2, cnt + 1 });
			visited[current * 2] = true;
		}
	}
	return cnt;
}
int main() {
	cin >> N >> K;
	visited.assign(MAX, false);
	cout <<bfs(N);
}
