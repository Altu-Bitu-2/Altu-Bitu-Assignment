#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
long long binarySearch(vector<long long>& v, int N, int M) {
	long long left = 0;
	//최대 시간
	long long right = *max_element(v.begin(), v.end()) * (N / M+1);
	long long time = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		//1초에는 M명이 탈 수 있음
		long long total = M;
		//n초 운행하는 놀이기구는 mid초 동안 mid/n명을 태울 수 있음
		for (int i = 0; i < M; i++) {
			total += mid / v[i];
		}
		if (total >= N) {
			time = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return time;
}

int main() {
	int N, M;
	//N명 M개 놀이기구
	cin >> N >> M;
	//N번째 친구가 몇초에 탔는지 알아야함
	vector<long long> v(M);
	for (int i = 0; i < M; i++) {
		cin >> v[i];
	}
	if (M >= N) {
		cout << N;
		return 0;
	}
	long long time= binarySearch(v, N, M); //M번째 사람은 time초에 탔음
	long long people = M;
	//cout << time;
	//time-1초까지 몇 명이 탔는지
	for (int i = 0; i < M; i++) {
		people += (time - 1) / v[i];
	}
	for (int i = 0; i < M; i++) {
		if (time % v[i] ==0) people++;
		if (people == N) {
			cout << i + 1;
			break;
		}
	}
}
