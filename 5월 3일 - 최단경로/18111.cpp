#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_TIME = 1e9;
int main() {
	int n, m, b;
	cin >> n >> m >> b;
	int answer[2] = { MAX_TIME, 0 };
	vector<vector<int>> ground(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
		}
	}
	for (int k = 256; k >= 0; k--) {
		int t = 0;
		int remove = 0;
		int add = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//블록 제거
				int height = ground[i][j] - k;
				if (height > 0) {
					remove += height;
				}
				//블록 채우기
				else if (height < 0) {
					//height자체가 음수이므로 -를 해줘서 +를 하게 해줘야함..!
					add -= height;
				}
			}
		}
		t = remove * 2 + add;
		if (remove+b>=add && t<answer[0]) {
			answer[0] = t;
			answer[1] = k;
		}
	}
	cout << answer[0] << " " <<answer[1];
}
