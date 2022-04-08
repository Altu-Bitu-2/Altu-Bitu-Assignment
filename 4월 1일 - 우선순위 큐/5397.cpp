#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		deque<char>dq;
		//커서 위치
		int idx = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (idx > 0) idx--;
			}
			else if (str[i] == '>') {
				if (idx == dq.size()) continue;
				idx++;
			}
			else if (str[i] == '-') {
				if (idx == 0) continue;
				dq.erase(dq.begin() + idx - 1);
				if (idx > 0) idx--;
			}
			else {
				dq.insert(dq.begin() + idx, str[i]);
				idx++;
			}
		}
		for (auto iter : dq) cout << iter;
		cout << "\n";
	}
}
