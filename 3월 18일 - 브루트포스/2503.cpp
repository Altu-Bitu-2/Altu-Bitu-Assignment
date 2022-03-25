#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef pair<int, int> pi;
map<int, bool> num;
void init() {
	for (int i = 123; i <= 987; i++) {
		string tmp = to_string(i);
		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) continue;
		if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0) continue;
		num[i] = true;
	}
}
pi guessResult(string tmp, string guess) {
	pi result;
	for (int i = 0; i < 3; i++) {
		int index = tmp.find(guess[i]);
		if (index != string::npos) {
			if (index == i) result.first++;
			else result.second++;
		}
	}
	return result;
}
void baseball(string guess, int strike, int ball) {
	for (auto iter : num) {
		//같은 위치에 숫자가 있으면 strike
		//같은 위치에는 없지만 숫자가 있으면 ball
		if (!iter.second) continue;
		string tmp = to_string(iter.first);
		pi result = guessResult(tmp, guess);
		if (result.first != strike || result.second != ball) num[iter.first] = false;
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

