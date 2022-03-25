#include <iostream>
#include <vector>
#include <set>
using namespace std;	
int cnt = 0;
void countWord(string str) {
	set<char>s;
	s.insert(str[0]);
	bool flag = false;
	for (int i = 1; i < str.length(); i++) {
		//문자가 이미 나왔는데 연속하지 않았을 때
		if (s.find(str[i]) != s.end() && str[i - 1] != str[i]) {
			flag = true;
			break;
		}
		else {
			s.insert(str[i]);
		}
	}
	if (!flag) cnt++;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		countWord(str);
	}
	cout << cnt;
}
