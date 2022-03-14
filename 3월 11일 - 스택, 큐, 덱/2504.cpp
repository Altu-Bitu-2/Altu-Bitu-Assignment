#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;
	stack <char> stack;
	bool flag=true;
	cin >> str;
	int cnt = 1;
	long long answer = 0;
	for (int i = 0; i < str.length(); i++) {
		//���� ��ȣ�� ���ÿ� ����
		if (str[i] == '(') {
			stack.push('(');
			cnt *= 2;
		}
		else if (str[i] == '[') {
			stack.push('[');
			cnt *= 3;
		}
		else if (str[i] == ')') {
			if (stack.empty()) {
				flag = false;
				break;
			}
			//���ÿ� ���� ���� �ٷ� �����̸�
			else if (stack.top() == '(') {
				if (str[i - 1] == '(') answer += cnt;
				stack.pop();
				cnt /= 2;
			}
			else {
				flag = false;
				break;
			}
		}
		else if (str[i] == ']') {
			if (stack.empty()) {
				flag = false;
				break;
			}
			else if (stack.top() == '[') {
				if (str[i - 1] == '[') answer += cnt;
				stack.pop();
				cnt /= 3;
			}
			else {
				flag = false;
				break;
			}
		}
	}
	if (!flag||!stack.empty()) cout << 0;
	else cout << answer;
}
