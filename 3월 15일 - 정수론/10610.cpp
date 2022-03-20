#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	string N;
	cin >> N;
	int len = N.length();
	long long sum = 0;
	//30의 배수이려면 끝이 0, 각 자리수를 더했을 때 3의배수가 되어야함
	for (int i = 0; i<len; i++) {
		sum += N[i]-'0';
	}
	sort(N.begin(), N.end(), greater<>());
	if (sum % 3 != 0 || N[len-1]!='0') {
		cout << -1;
		return 0;
	}
	cout << N;
}

