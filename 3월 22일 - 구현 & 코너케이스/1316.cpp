#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool isGroupWord(string str) {
	vector<bool> s(26, false);
	s[str[0] - 97] = true;
	bool flag = false;
	for (int i = 1; i < str.length(); i++) {
		//문자가 이미 나왔는데 연속하지 않았을 때
		if (s[str[i] - 97] && str[i] != str[i - 1]) {
			flag = true;
			return false;
		}
		else {
			s[str[i] - 97] = true;
		}
	}
	return true;
}
int main() {
	int T;
	cin >> T;
	int cnt = 0;
	while (T--) {
		string str;
		cin >> str;
		if (isGroupWord(str)) cnt++;
	}
	cout << cnt;
}
