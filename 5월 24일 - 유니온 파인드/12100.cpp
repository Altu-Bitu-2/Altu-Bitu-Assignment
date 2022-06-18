#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, answer;
vector<vector<int>> moveDown(vector<vector<int>>& board) {
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) continue;
			int k = i+1;

			while (k <= n - 1) {
				//블럭 두개 값이 같으면서 합쳐지지 않았던 블록이라면 합침
				if (board[k][j] == board[k - 1][j] && !visited[k][j]) {
					board[k][j] += board[k - 1][j];
					board[k - 1][j] = 0;
					visited[k][j] = true;
					break;
				}
				//블록이 0이라면 합치고 또 합쳐질 수 있으므로 방문처리는 하지 않음 
				else if (board[k][j] == 0) {
					board[k][j] += board[k - 1][j];
					board[k - 1][j] = 0;
				}
				//자신과 다른 블록과 부딛치면 탐색 x
				else break;
				k++;
			}
		}
	}
	return board;
}
vector<vector<int>> moveUp(vector<vector<int>>& board) {
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) continue;
			int k = i-1;
			while (k >= 0) {
				if (board[k][j] == board[k + 1][j] && !visited[k][j]) {
					board[k][j] += board[k + 1][j];
					board[k + 1][j] = 0;
					visited[k][j] = true;
					break;
				}
				else if (board[k][j] == 0) {
					board[k][j] += board[k + 1][j];
					board[k + 1][j] = 0;
				}
				else break;
				k--;
			}
		}
	}

	return board;
}
vector<vector<int>> moveRight(vector<vector<int>>& board) {
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = n-2; j >= 0; j--) {
			if (board[i][j] == 0) continue;
			int k = j+1;
			while (k <= n - 1) {
				if (board[i][k] == board[i][k - 1] && !visited[i][k]) {
					board[i][k] += board[i][k - 1];
					board[i][k - 1] = 0;
					visited[i][k] = true;
					break;
				}
				else if (board[i][k] == 0) {
					board[i][k] += board[i][k - 1];
					board[i][k - 1] = 0;
				}
				else break;
				k++;
			}
		}
	}
	return board;
}

vector<vector<int>> moveLeft(vector<vector<int>>& board) {
	vector<vector<bool>>visited(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (board[i][j] == 0) continue;
			int k = j-1;
			while (k >= 0) {
				if (board[i][k] == board[i][k + 1] && !visited[i][k]) {
					board[i][k] += board[i][k + 1];
					board[i][k + 1] = 0;
					visited[i][k] = true;
					break;
				}
				else if (board[i][k] == 0) {
					board[i][k] += board[i][k + 1];
					board[i][k + 1] = 0;
				}
				else break;
				k--;
			}
		}
	}
	return board;
}

int getMax(vector<vector<int>>& board) {
	int max_block = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_block = max(max_block, board[i][j]);
		}
	}
	return max_block;
}

void reset(vector<vector<int>>& board, vector<vector<int>>& copyBoard) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = copyBoard[i][j];
		}
	}
}

void solve(int cnt, vector<vector<int>> &board) {
	vector<vector<int>> copyBoard(n, vector<int>(n));
	if (cnt == 5) {
		answer = max(getMax(board), answer);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copyBoard[i][j] = board[i][j];
		}
	}	
	vector<vector<int>> leftBoard = moveLeft(board);
	solve(cnt + 1, leftBoard);
	reset(board, copyBoard); //board값이 계속 바뀌므로 계속 처음 값으로 되돌려줘야한다

	vector<vector<int>> rightBoard = moveRight(board);
	solve(cnt + 1, rightBoard);
	reset(board, copyBoard);

	vector<vector<int>> upBoard = moveUp(board);
	solve(cnt + 1, upBoard);
	reset(board, copyBoard);

	vector<vector<int>> downBoard = moveDown(board);
	solve(cnt + 1, downBoard);
	reset(board, copyBoard);
}

int main() {
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	solve(0, board);
	cout << answer;
}


