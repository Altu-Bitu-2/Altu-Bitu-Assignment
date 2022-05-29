#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>parent;

int findParent(int node) {
	if (parent[node] < 0) return node;
	return parent[node] = findParent(parent[node]);
}

void unionPeople(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	parent[yp] = xp;
}

int main() {
	int n, m, true_num;
	cin >> n >> m;
	cin >> true_num;
	parent.assign(n+1, -1);
	vector<int> truth(true_num);
	//진실을 아는 사람들
	for (int i = 0; i < true_num; i++) {
		cin >> truth[i];
	}
	vector<vector<int>> party(m);
	for (int i = 0; i < m; i++) {
		int num; //파티에 참여하는 사람 수
		cin >> num;
		party[i].assign(num, 0);
		for (int j = 0; j < num; j++) {
			cin >> party[i][j];
		}
		for (int j = 1; j < num; j++) {
			//같은 그룹으로 묶기
			if (findParent(party[i][0])==findParent(party[i][j])) continue;
			unionPeople(party[i][0], party[i][j]);
		}
	}
	int cnt = m;
	for (int i = 0; i < m; i++) {
		bool flag = true;
		for (int j = 0; j < party[i].size(); j++) {
			for (int k = 0; k < truth.size(); k++) {
				if (findParent(party[i][j]) == findParent(truth[k])) {
					//이 파티는 못감
					flag = false;
					break;
				}
			}
		}
		if (!flag) cnt--;
	}
	cout << cnt;
}
