#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N;
		set<int> num;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			num.insert(a);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int b;
			cin >> b;
			if (num.find(b) != num.end()) cout << 1 << "\n";
			else cout << 0<< "\n";
		}
	}
}
