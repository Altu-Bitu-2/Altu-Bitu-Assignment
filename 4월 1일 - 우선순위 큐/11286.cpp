#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pi;
int main() {
	int N;
	cin >> N;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	while (N--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << "\n";
				pq.pop();
			}
			else cout << "0\n";
		}
		//���밪��, �ڽ��� ���� ����
		else {
			pq.push({ abs(x), x });
		}
	}
}
