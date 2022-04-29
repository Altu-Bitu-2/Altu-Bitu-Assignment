#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int steal(vector<int>& v, int N, int M, int K) {
	int cnt = 0;
	int sum = 0;
	int left = 0;
	int right = M - 1;
	for (int i = 0; i < M; i++) {
		sum += v[i];
	}
	//N과 M이 같을 때
	if (N == M) {
		if (sum < K) return 1;
		else return 0;
	}
	//윈도우의 크기를 M으로 하고 옆으로 한칸씩 민다
	while (left<N) {
		if (sum < K) cnt++;
		sum -= v[left];
		left++;
		right++;
		sum += v[right];
	}
	return cnt;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M, K;
		cin >> N >> M >> K;
		vector<int> v(N+M);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		//M-1개수만큼 뒤에 더 추가해줌
		for (int i = 0; i < M-1; i++) {
			v[i + N] = v[i];
		}
		cout << steal(v, N, M, K) <<"\n";
	}
}
