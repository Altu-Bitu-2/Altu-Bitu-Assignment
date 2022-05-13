#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, string> si;
int binarySearch(vector<si>& v, int N, int power) {
	int left = 0;
	int right = N - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (v[mid].first >= power) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<si> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].second >> v[i].first;
	}
	int power = 0;
	for (int i = 0; i < M; i++) {
		cin >> power;
		cout << v[binarySearch(v, N, power)].second << "\n";
	}
}
