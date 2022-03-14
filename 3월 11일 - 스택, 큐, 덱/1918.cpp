#include <iostream>
#include <vector>
#include <stack>
using namespace std;	
stack<char> st;
string postfix;
void infixToPostfix(char op) {
	switch (op) {
		//해당 연산자보다 stack에 있는 연산자의 우선순위가 높을 경우 pop
		case '*':
		case '/':
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				postfix += st.top();
				st.pop();
			}
			st.push(op);
			break;
		case '+':
		case '-':
			while (!st.empty() && st.top()!='(') {
				postfix += st.top();
				st.pop();
			}
			st.push(op);
			break;
		case '(':
			st.push(op);
			break;
		case ')':			
			while (!st.empty() && st.top() != '(') {
				postfix += st.top();
				st.pop();
			}
			// '(' pop
			st.pop();
			break;
	}
}
int main() {
	string exp;
	cin >> exp;
	for (int i = 0; i < exp.length(); i++) {
		char op = exp[i];
		//피연산자는 바로 출력
		if (op >= 'A' && op <= 'Z') {
			postfix += op;
		}
		else {
			infixToPostfix(op);
		}
	}
	//스택에 있는 것들을 pop
	while (!st.empty()) {
		postfix += st.top();
		st.pop();
	}
	cout << postfix;
}
