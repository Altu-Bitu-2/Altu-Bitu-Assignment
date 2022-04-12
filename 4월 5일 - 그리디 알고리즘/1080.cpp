#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int>> vi;
//행렬 원소를 뒤집는 함수
void change(vi &A, int r, int c) {
	for (int i = r; i <r + 3; i++) {
		for (int k = c; j < c + 3; j++) {
			A[k][l] = !A[k][l];
		}
	}
}
//행렬이 같은지 판별하는 함수
bool isSame(vi& A, vi& B, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int N, M;
	cin >> N >> M;
	vi A(N, vector<int>(M));
	vi B(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &A[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &B[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M-2; j++) {
			//값이 다르다면 바꿔줌
			if (A[i][j] != B[i][j]) {
				change(A, i, j);
				cnt++;
			}
		}
	}
	if (isSame(A, B, N, M)) cout << cnt;
	else cout << -1;
}
