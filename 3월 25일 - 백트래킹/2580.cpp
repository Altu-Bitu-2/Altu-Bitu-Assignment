#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pi;
vector<vector<int>>board(9, vector<int>(9));
vector<pi>points;
bool flag = false;
int cnt = 0;
bool check(pi p) {
	//구역을 3*3으로 나눔
	int x = p.first / 3;
	int y = p.second / 3;
	for (int i = 0; i < 9; i++) {
		//같은 행에 같은 숫자가 있는지
		if (board[p.first][i] == board[p.first][p.second] && i != p.second)
			return false;
		//같은 열에 같은 숫자가 있는지
		if (board[i][p.second] == board[p.first][p.second] && i != p.first)
			return false;
	}
	//같은 구역에 같은 숫자가 있는지
	for (int i = 3 * x; i < 3 * x + 3; i++) {
		for (int j = 3 * y; j < 3 * y + 3; j++) {
			if (i == p.first|| j == p.second) continue;
			if (board[i][j] == board[p.first][p.second]) 
				return false;
		}
	}
	return true;
}
void sudoku(int N) {
	//종료조건: 모든 빈칸이 채워졌을 때
	if (N == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		flag = true;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		//1부터 9까지 숫자를 넣어서 유효하면 다음 빈칸으로 넘어감
		board[points[N].first][points[N].second] = i;
		if (check(points[N])) sudoku(N + 1);
		if (flag) return;
	}
	//결과가 유효하지 않으면 다시 비워둠
	board[points[N].first][points[N].second] = 0;
	return;
}

int main() {
	pi point;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				//채워야할 빈칸 개수
				cnt++;
				//points 벡터에 빈칸 위치 저장
				points.push_back({ i,j });
			}
		}
	}
	sudoku(0);
}

