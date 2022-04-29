#include <iostream>
#include <vector>
#include<deque>
#include <algorithm>
using namespace std;
int maxDish(int n, int k, int c, vector<int>&dish) {
	int max_dish = 0;
	vector<int>visited(3001, 0);
	for (int i = 0; i < k; i++) {
		if (visited[dish[i]]==0) {
			max_dish++;
		}
		//중복되는 초밥수 세기
		visited[dish[i]]++;
	}
	int cnt = max_dish;
	if (visited[c] == 0) max_dish++;
	for (int i = k; i < n+k-1; i++) {
		//윈도우를 미는 과정
		//일단 중복 수를 하나 줄이고, 다음 윈도우에 해당 초밥이 없다면 종류수도 줄임
		visited[dish[i - k]]--;
		if (visited[dish[i - k]] == 0) cnt--;

		//윈도우에 들어오는 초밥이 없다면 카운트를 올려줌
		if (visited[dish[i]] == 0) cnt++;
		visited[dish[i]]++;

		//현재 윈도우에 쿠폰 초밥이 없다면 카운트를 올려줌
		if (visited[c] == 0) max_dish = max(max_dish, cnt + 1);
		else max_dish = max(max_dish, cnt);
	}
	return max_dish;
}
int main() {
	int n, d, k, c; //접시 수, 초밥 가짓수, 연속해서 먹는 수, 쿠폰 번호
	cin >> n >> d >> k >> c;
	vector<int>dish(n+k-1);
	for (int i = 0; i < n; i++) {
		cin >> dish[i];
	}
	for (int i = 0; i < k - 1; i++) {
		dish[n + i] = dish[i];
	}
	cout << maxDish(n, k, c, dish);
}
