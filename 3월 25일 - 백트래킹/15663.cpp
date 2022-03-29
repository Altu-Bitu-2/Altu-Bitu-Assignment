#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;	
int N, M;	
vector <int> num;
vector <int> answer;
vector <bool> visited;
void backtracking(int depth) {
	//M만큼 고르면 종료
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}

	int check = -1;
	for (int i = 0; i < N; i++) {
		//(1, 7) (1, 9) (1, 9)로 중복이 나오므로 이전에 선택한 값이면 탐색하지 않음
		if (!visited[i]&&check!=num[i]) {
			visited[i] = true;
			check = num[i];
			answer[depth] = num[i];
			backtracking(depth+1);
			visited[i] = false;
		}

	}
}
int main() {
	cin >> N >> M;
	num.assign(N, 0);
	answer.assign(M+1, 0);
	visited.assign(N + 1, false);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	backtracking(0);
}
