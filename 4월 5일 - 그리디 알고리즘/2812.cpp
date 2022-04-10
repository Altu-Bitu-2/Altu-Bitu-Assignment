#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	string num;
	cin >> num;
	deque<char> dq;
	dq.push_back(num[0]);	
	int cnt = 0;
	for (int i = 1; i < N; i++) {
		//deque에 있는 값보다 들어오는 값이 크다면 deque에서 제거
		while (cnt!=K && !dq.empty()&& dq.back() < num[i]) {
			dq.pop_back();
			cnt++;
		}
		dq.push_back(num[i]);
	}
	cnt = 0;
	while (true) {
		cout << dq.front();
		dq.pop_front();
		cnt++;
		if (cnt == N - K) break;
	}
}
