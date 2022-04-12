#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
int getClassNum(int N, vector<pi>& v) {
	priority_queue<int, vector<int>, greater<int>>pq;
	pq.push(0);
	for (int i = 0; i < N; i++) {
		int start = v[i].first;
		int end = v[i].second;
		int prev = pq.top();
		if (start >= prev) pq.pop();
		//새로운 방 배정
		pq.push(end);
	}
	return pq.size();
}
int main() {
	int N;
	cin >> N;
	vector<pi> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	cout << getClassNum(N, v);
}
