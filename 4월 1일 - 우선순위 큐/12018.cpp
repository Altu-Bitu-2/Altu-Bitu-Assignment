#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		//신청 인원, 수강 인원
		int P, L;
		cin >> P >> L;
		vector<int> v(P);
		for (int j = 0; j < P; j++) {
			cin >> v[j];
		}
		//만약 수강 인원보다 신청 인원이 적으면 마일리지 1로 신청 가능
		if (P < L) {
			pq.push(1);
			continue;
		}
		//가장 적은 마일리지를 쓰려면 P-L등의 마일리지를 사용하면 됨
		sort(v.begin(), v.end());
		pq.push(v[P - L]);
	}
	int cnt = 0;
	while (!pq.empty()) {
		int mileage = pq.top();
		pq.pop();
		if (M < mileage) break;
		M -= mileage;
		cnt++;
	}
	cout << cnt;
}
1
