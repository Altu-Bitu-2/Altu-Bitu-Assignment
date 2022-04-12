#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long getOil(int current, int N, vector<long long>& price, vector<long long>& dist) {
	long long oil = 0;
	for (int i = 0; i < N - 1; i++) {
		//현재 가격이 다음 주유소 가격보다 작다면 다음 길이도 현재 가격으로 주유
		if (current > price[i]) current = price[i];
		oil += current * dist[i];
		//아니라면 가격 갱신
	}
	return oil;
}
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
		cout << price[0] * dist[0];
		return 0;
	}
	//현재 가격
	cout << getOil(price[0], N, price, dist);
}
