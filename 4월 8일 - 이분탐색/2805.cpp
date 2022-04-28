#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cutTree(int N, int M, vector<long long>& tree) {
	long long left = 0;
	long long right = tree[N - 1];
	long long answer = 0;
	while (left <= right) {
		long long total = 0;
		long long mid = (left + right) / 2;
		for (int i = 0; i < N; i++) {
			if (tree[i] - mid > 0) total += tree[i] - mid;
		}
		//나무가 모자르면 높이를 낮춰 베어야 함
		if (total < M) right = mid - 1;
		else {
			answer = max(answer, mid);
			left = mid + 1;
		}
	}
	return answer;
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<long long> tree(N);
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());
	//나무는 최소 10m, 최대 20m 벨 수 있음
	cout << cutTree(N, M, tree);

}