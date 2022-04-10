#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long> dist(N - 1);
	vector<long long> price(N);
	for (int i = 0; i < N - 1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}
	if (N == 2) {
		cout << price[0]*dist[0];
		return 0;
	}
	long long oil = 0;
	//현재 가격
	int temp = price[0];
	for (int i = 0; i < N - 1; i++) {
		//현재 가격이 다음 주유소 가격보다 작다면 다음 길이도 현재 가격으로 주유
		if (temp <= price[i]) {
			oil += temp * dist[i];
		}
		//아니라면 가격 갱신
		else {
			oil += price[i] * dist[i];
			temp = price[i];
		}
	}
	cout << oil;
}
