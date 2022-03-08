#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector <int> cost(N);
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}
	sort(cost.begin(), cost.end(), greater<>());
	long long money = 0;
	for (int i = 0; i < N; i++) {
		int tip = cost[i] - i;
		if (tip < 0) break;
		money += tip;
	}
	cout << money;
}