#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, P;
	cin >> N >> P;
	vector<vector<int>> v(7, vector<int>(P));
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int line, fret;
		cin >> line >> fret;
		//손 떼가는 과정
		while (!v[line].empty() && v[line].back() > fret) {
			cnt++;
			v[line].pop_back();
		}
		//누르고 있는 손이 없거나 가장 뒤의 fret이 현재 입력보다 작은데 같진 않을 때
		//바로 누를 수 있음
		if (v[line].empty() || v[line].back() != fret) {
			cnt++;
			v[line].push_back(fret);
		}
	}
	cout << cnt;
}

