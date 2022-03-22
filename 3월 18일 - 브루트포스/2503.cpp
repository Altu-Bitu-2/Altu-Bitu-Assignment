#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<int, bool> num;
void init() {
	for (int i = 123; i <= 987; i++) {
		string tmp = to_string(i);
		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) continue;
		if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) continue;
		num[i] = true;
	}
}
void baseball(string guess, int strike, int ball) {
	for (auto iter : num) {
		//같은 위치에 숫자가 있으면 strike
		//같은 위치에는 없지만 숫자가 있으면 ball
		if (!iter.second) continue;
		string tmp = to_string(iter.first);
		int s = 0, b = 0;
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (j == k && tmp[j] == guess[k]) s++;
				if (j != k && tmp[j] == guess[k]) b++;
			}
		}
		if (s != strike || b != ball) num[iter.first] = false;
	}
}
int main() {
	int N;
	//123~987까지의 숫자 중에서 입력 조건과 일치하는 숫자만 남김
	cin >> N;	
	init();
	while (N--) {
		string guess;
		int strike, ball;
		cin >> guess >> strike >> ball;	
		baseball(guess, strike, ball);
	}
	int cnt = 0;
	for (auto iter : num) {
		if (iter.second) cnt++;
	}
	cout << cnt;
}

