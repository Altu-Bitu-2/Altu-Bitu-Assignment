#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sumOfNum(string s) {
	int total = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			total += s[i] - '0';
		}
	}
	return total;
}
bool cmp(const string& a, const string& b) {
	if (a.length() == b.length()) {
		if (sumOfNum(a) == sumOfNum(b)) return a < b;
		return sumOfNum(a) < sumOfNum(b);
	}
	return a.length() < b.length();
}
int main() {
	int N;
	cin >> N;
	vector<string> serial(N);
	for (int i = 0; i < N; i++) {
		cin >> serial[i];
	}
	sort(serial.begin(), serial.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout<< serial[i]<<"\n";
	}
}
