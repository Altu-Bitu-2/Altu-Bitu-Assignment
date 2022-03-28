#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		//최대 4번의 사이클로 맨 끝자리가 바뀜
		int mod = b % 4;
		if (mod == 0) mod += 4;
		int data = pow(a, mod);
		string str = to_string(data);
		reverse(str.begin(), str.end());
		if (str[0] == '0') cout << "10" << "\n";
		else cout << str[0]<<"\n";
	}
}
