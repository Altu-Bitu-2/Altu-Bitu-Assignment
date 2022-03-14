#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;	
deque <int> dq;
void card(int v, int i) {
	int temp = 0;
	switch (v) {
	case 1:
		dq.push_front(i);
		break;
	case 2:
		temp = dq.front();
		dq.pop_front();
		dq.push_front(i);
		dq.push_front(temp);
		break;
	case 3:
		dq.push_back(i);
		break;
	}
}
int main() {
	int N;
	cin >> N;
	vector <int> v;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	reverse(v.begin(), v.end());
	for (int i = 1; i <= N; i++) {
		card(v[i-1], i);
	}
	for (int i = 0; i < N; i++) {
		cout << dq[i] << " ";
	}
}

