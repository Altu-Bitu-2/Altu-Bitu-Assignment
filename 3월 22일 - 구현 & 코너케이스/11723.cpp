#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	vector<bool> num(21, false);
	while (T--) {
		string op;
		int n = 0;
		cin >> op;		
		if (op == "all") {
			for (int i = 1; i <= 20; i++) {
				num[i] = true;
			}
			continue;
		}
		if (op == "empty") {
			for (int i = 1; i <= 20; i++) {
				num[i] = false;
			}
			continue;
		}
		cin >> n;
		if (op == "add") {
			num[n] = true;
		}
		else if (op == "check") {
			if (num[n]) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (op == "remove") {
			num[n] = false;
		}
		else if (op == "toggle") {
			if (num[n]) num[n] = false;
			else num[n] = true;
		}

	}
}
