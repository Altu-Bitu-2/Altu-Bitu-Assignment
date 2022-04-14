#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
vector <int> tree;
int binarySearch(int low, int high, int M) {
	int answer = 0;
	while (low <= high) {
		int H = (low + high) / 2;	
		long long cnt = 0;
		for (int i = 0; i < tree.size(); i++) {
			if (tree[i] - H > 0) cnt = cnt+ tree[i] - H;
		}
		if (cnt < M) high = H - 1;
		else {
			if (answer < H) answer = H;
			low = H + 1;
		}
	}
	return answer;
}

int main() {
	int N, M; //나무 수, 필요한 나무 길이
	cin >> N >> M;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &tree[i]);
	}
	sort(tree.begin(), tree.end());
	printf("%d",binarySearch(0, tree.back(), M));
}
