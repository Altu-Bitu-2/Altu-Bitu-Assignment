#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//��� ���Ҹ� ������ �Լ�
void change(vector<vector<int>>&A, int i, int j) {
	for (int k = i; k < i + 3; k++) {
		for (int l = j; l < j + 3; l++) {
			A[k][l] = !A[k][l];
		}
	}
}
//����� ������ �Ǻ��ϴ� �Լ�
bool isSame(vector<vector<int>>& A, vector<vector<int>>& B, int N, int M) {
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
	vector<vector<int>> A(N, vector<int>(M));
	vector<vector<int>> B(N, vector<int>(M));
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
	//3*3���� ������ ���� ����� �ƴ� �� 
	if ((N < 3 || M < 3)&&!isSame(A,B,N,M)) {
		cout << -1;
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M-2; j++) {
			//���� �ٸ��ٸ� �ٲ���
			if (A[i][j] != B[i][j]) {
				change(A, i, j);
				cnt++;
			}
		}
	}
	if (isSame(A, B, N, M)) cout << cnt;
	else cout << -1;
}
