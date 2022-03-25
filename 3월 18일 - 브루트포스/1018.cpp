#include <iostream>
#include <vector>
using namespace std;
const int CHESS = 64;
char chessboard(int x, int y) {
	if ((x + y) % 2 == 0) return 'W';
	else return 'B';
}
int check(vector<vector<char>>&chess, int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (chess[i][j] != chessboard(i, j)) cnt++;
		}
	}
	return min(cnt, CHESS-cnt);
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<char>>chess(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >>chess[i][j];
		}
	}
	int answer = N * M;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			answer=min(answer,check(chess, i, j));
		}
	}
	cout << answer;
}
