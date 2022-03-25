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
	set<int>s;
	while (T--) {
		string op;
		int n;
		cin >> op;
		if (op == "add") {
			cin >> n;
			s.insert(n);
		}
		else if (op == "check") {
			cin >> n;
			if (s.find(n) !=s.end()) cout << "1"<<"\n";
			else cout << "0" << "\n";
		}
		else if (op == "remove") {
			cin >> n;
			s.erase(n);
		}
		else if (op == "toggle") {
			cin >> n;
			if (s.find(n) != s.end()) s.erase(n);
			else s.insert(n);
		}
		else if (op == "all") {
			for (int i = 1; i <= 20; i++) {
				s.insert(i);
			}
		}
		else if (op == "empty") {
			s.clear();
		}
	}
}
