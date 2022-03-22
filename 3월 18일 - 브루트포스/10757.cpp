#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string add(string a, string b) {
	int carry = 0;
	string answer;
	int len_a = a.length();
	int len_b = b.length();
	while (len_a > 0 || len_b > 0) {
		int num_a = 0, num_b = 0;
		int sum = 0;
		if (len_a > 0) {
			num_a = a[len_a - 1] - '0';
			len_a--;
		}
		if (len_b > 0) {
			num_b = b[len_b - 1] - '0';
			len_b--;
		}
		sum = num_a + num_b + carry;
		carry = sum / 10;
		answer += ((sum % 10) + '0');
	}
	if (carry) answer += '1';
	reverse(answer.begin(), answer.end());
	return answer;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << add(a, b);
}
