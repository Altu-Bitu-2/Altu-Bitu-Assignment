#include <iostream>
#include <algorithm>
#include <map>
using namespace std;	
map<char, int> m;
string palindrome() {
	string temp;
	//해당 알파벳의 절반값만큼 temp에 저장
	for (auto iter : m) {
		for (int i = 0; i < iter.second / 2; i++) {
			temp += iter.first;
		}
	}
	return temp;
}
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		//map에 존재하지 않는 key를 참조하면 자동으로 insert연산이 실행된다.
		m[str[i]]++;
	}
	int odd = 0;
	char odd_char;
	for (auto iter : m) {
		if (iter.second % 2 != 0) {
			odd++;
			odd_char = iter.first;
		}
	}
	
	string temp;
	string answer;
	//홀수 개인 알파벳이 1개 이상이면 불가능하므로 출력 후 종료
	if (odd > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	else {
		temp = palindrome();
		answer = temp;
		reverse(temp.begin(), temp.end());
		//모두 짝수이면 그냥 바로 reverse한 string이랑 합침
		if (odd == 0) 
			answer += temp;
		//모두 짝수가 아니라면 가운데에 홀수개인 알파벳 1개를 삽입
		else {
			answer += odd_char;
			answer += temp;
		}
	}
	cout << answer;
}
