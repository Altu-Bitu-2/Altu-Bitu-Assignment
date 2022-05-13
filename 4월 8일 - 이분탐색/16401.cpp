#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check(int N, int mid, vector<int> &v) {		
	int cnt = 0;
	//mid 길이로 조카에게 줄 수 있는 과자의 개수
	for (int i = 0; i < N; i++) {
		cnt += v[i]/ mid;
	}
	return cnt;
}
int main() {
	int M, N;
	cin >> M >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int left = 1;
	int right = v[N-1];
	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = check(N, mid, v);
		if (cnt >= M) {
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer;

}	
