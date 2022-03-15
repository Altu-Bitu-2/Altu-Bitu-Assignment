#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

int main() {
	string str;
	stack <char> stack;
	bool flag = true;
	cin >> str;
	int cnt = 1;
	long long answer = 0;
	map <char, char> bracket;
	map <char, int> num;
	bracket[')'] = '(';
	bracket[']'] = '[';
	num['('] = 2;
	num['['] = 3;
	for (int i = 0; i < str.length(); i++) {
		char op = str[i];
		switch (op) {
			//여는 괄호는 스택에 넣음
		case '(': case '[':
			stack.push(op);
			cnt *= num[op];
			break;
		case ')': case ']':
			if (stack.empty() || stack.top() != bracket[op]) {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == bracket[op]) {
				answer += cnt;
			}
			cnt /= num[bracket[op]];
			stack.pop();
			break;
		}
	}
	if (!stack.empty()) cout << 0;
	else cout << answer;
}
