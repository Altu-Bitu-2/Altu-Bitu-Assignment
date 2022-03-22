#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> init(int N) {
	vector<bool>arr(N, false);
	for (int i = 0; i < 3; i++) {
		arr[i] = true;
	}
	sort(arr.begin(), arr.end());
	return arr;
}
int main() {
	int N, M;
	int answer = 0;
	cin >> N >> M;
	vector<int> card(N);
	vector<bool> temp = init(N);
	init(N);
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	do {
		int sum = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i]) sum += card[i];
		}
		if (sum <= M && (M - sum < M - answer)) {
			answer = sum;
		}
	} while (next_permutation(temp.begin(), temp.end()));
	cout << answer;
}
