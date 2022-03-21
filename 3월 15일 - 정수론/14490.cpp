#include <iostream>
#include <string>
using namespace std;
int gcdRecursion(int a, int b) {
	if (b == 0) return a;
	return gcdRecursion(b, a % b);
}
int main() {
	string str;
	cin >> str;
	int n = 0, m = 0;
	int i = 1;
	while (true) {
		if (str[i] == ':') {
			n = stoi(str.substr(0, i));
			m = stoi(str.substr(i + 1, str.length()));
			break;
		}
		i++;
	}
	int gcd=gcdRecursion(max(n, m), min(n, m));
	cout << n/gcd <<":" << m/gcd;
}

