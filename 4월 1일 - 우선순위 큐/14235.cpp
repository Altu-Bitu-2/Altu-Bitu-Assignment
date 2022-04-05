#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;		
	priority_queue<int> pq;
	while (N--) {
		int a;
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << -1 << "\n";
			}
			//가장 가치가 큰 선물을 줌
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
			continue;
		}
		//a개의 선물 충전
		for (int i = 0; i < a; i++) {
			int n;
			cin >> n;
			pq.push(n);
		}
	}
}
