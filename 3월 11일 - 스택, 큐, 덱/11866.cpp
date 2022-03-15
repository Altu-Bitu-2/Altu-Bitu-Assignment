#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;	

int main() {
	int N, K;
	cin >> N >> K;
	queue<int>q;
	vector<int>answer;
	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}	
	cout << "<";
	while (!q.empty()) {
		//K-1번째까지 뒤에 붙이고 앞에 pop
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty()) cout << ", ";
	}
	cout << ">";
}

