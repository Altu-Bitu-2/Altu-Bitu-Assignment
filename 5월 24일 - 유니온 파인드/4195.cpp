#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 200000;
vector<int> root(MAX + 1);
vector<int> friend_num(MAX + 1);

void init(int N) {
	for (int i = 0; i <= MAX; i++) {
		root[i] = -1;
		friend_num[i] = 1;
	}
}

int findParent(int node) {
	if (root[node]<0) return node;
	return root[node] = findParent(root[node]);
}

void unionFriends(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp != yp) {
		root[xp] = yp;
		friend_num[yp] += friend_num[xp];
		friend_num[xp] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<string, int>m;
		init(n);
		int num = 1;
		for (int i = 0; i < n; i++) {
			string x, y;
			cin >> x >> y;
			if (m.find(x) == m.end()) m[x] = num++;
			if (m.find(y) == m.end()) m[y] = num++;
			int xp = findParent(m[x]);
			int yp = findParent(m[y]);
			unionFriends(m[x], m[y]);
			cout << friend_num[yp] << "\n";

		}
	}
}
