#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//비용이 적은 두 파일을 합치는 함수
long long mergeFile(priority_queue<long long, vector<long long>, greater<long long>> &pq) {
	long long answer = 0;
	while (pq.size() > 1) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		answer += a + b;
		pq.push(a + b);
	}
	return answer;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		priority_queue<long long, vector<long long>, greater<long long>>pq;
		for (int i = 0; i < N; i++) {
			int p;
			cin >> p;
			pq.push(p);
		}
		//비용이 작은 순서대로 pop한 뒤 더하고 다시 큐에 삽입
		long long answer = mergeFile(pq);
		cout << answer <<"\n";
	}
}
