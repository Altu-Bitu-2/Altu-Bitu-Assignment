#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
void boy(vector<int> &v, int switch_num) {
	//받은 번호의 배수면 스위치 상태를 바꿈
	for (int i = 1; i < v.size(); i++) {
		if (i % switch_num == 0) {
			v[i] = !v[i];
		}
	}
}

void girl(vector<int>& v, int switch_num) {
	//스위치 수가 첫번호거나 끝번호라면 자기 자신만 바꿈
	if (switch_num == 1 || switch_num == n) {
		v[switch_num] = !v[switch_num];
		return;
	}
	int cnt = 1;
	while (true) {
		//대칭이 아니라면 종료
		if (v[switch_num - cnt] != v[switch_num + cnt]) {
			cnt--;
			break;
		}
		//범위에 넘어가면 종료
		if (switch_num - cnt == 1 || switch_num + cnt == n) break;
		cnt++;
	}
	//바꿀 범위만큼 바꿈
	for (int i = switch_num -cnt; i <= switch_num +cnt; i++) {
		v[i] = !v[i];
	}
}

int main() {

	cin >> n;
	vector<int> v(n+1);
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	cin >> m;

	//성별, 받은 스위치 번호
	vector<pair<int, int>> students(m);
	for (int i = 0; i < m; i++) {
		cin >> students[i].first >> students[i].second;
	}
	for (int i = 0; i < m; i++) {
		if (students[i].first == 1) boy(v, students[i].second);
		else girl(v, students[i].second);
	}
	for (int i = 1; i <= n; i++) {
		cout << v[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
}


