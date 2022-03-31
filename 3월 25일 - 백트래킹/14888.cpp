#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;
int N;
int max_answer = -1e9;	
int min_answer = INF;
vector<int>A;
vector<int>op(4);
void backtracking(int depth, int result) {
	if (depth == N) {
		max_answer = max(max_answer, result);
		min_answer = min(min_answer, result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			switch (i) {
			case 0:
				backtracking(depth + 1, result + A[depth]);
				break;
			case 1:
				backtracking(depth + 1, result - A[depth]);
				break;
			case 2:
				backtracking(depth + 1, result * A[depth]);
				break;
			case 3:
				backtracking(depth + 1, result / A[depth]);
				break;
			}
			op[i]++;
		}
	}
}
int main() {
	cin >> N;
	A.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	//더하기, 빼기, 곱하기, 나누기
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	backtracking(1, A[0]);
	cout << max_answer << "\n" << min_answer;
}
