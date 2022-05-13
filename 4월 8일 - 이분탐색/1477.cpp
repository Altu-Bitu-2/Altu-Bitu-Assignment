#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarySearch(int L, vector<int>&v, int M) {
	int left = 1;
	int right = L;
	while (left <= right) {	
		//거꾸로 생각해서 사이 거리가 최소 mid일 때 M개의 휴게소를 더 설치할 수 있는지
		int mid = (left + right) / 2;
		int dist = 0;
		int cnt = 0;
		for (int i = 1; i < v.size(); i++) {
			dist = v[i] - v[i - 1];
			cnt += dist / mid;
			//나눴을 때 0이 되면 그 자리에는 이미 휴게소가 있다는 뜻
			if (dist % mid==0) {
				cnt--;
			}
		}
		if (cnt > M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}
int main() {
	int N, M, L;
	cin >> N >> M >> L;
	vector<int> v(N + 2);
	v[0] = 0;
	v[1] = L;
	for (int i = 2; i < N+2; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << binarySearch(L, v, M);
}
