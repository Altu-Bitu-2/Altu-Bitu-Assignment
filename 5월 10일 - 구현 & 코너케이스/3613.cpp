#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string toLowerCase(string str) {
	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}
string toCpp(string str) {
	vector<int> temp;
	//대문자가 나오는 경우의 인덱스를 모두 temp배열에 담아줌
	for (int i = 0; i < str.size(); i++) {
		if (isupper(str[i])) {
			temp.push_back(i);
		}
	}
	str=toLowerCase(str);
	int cnt = 0;
	//대문자가 나왔던 곳에 _를 끼워넣음
	for (int i = 0; i < temp.size(); i++) {
		str.insert(temp[i]+cnt, "_");
		cnt++;
	}
	return str;
}
string toJava(string str) {
	vector<int> temp;
	for (int i = 0; i < str.size(); i++) {
		if (str[i]=='_') {
			char c = str[i + 1];
			//4. __가 연속으로 나오는 경우 에러
			if (c == '_') {
				return "Error!";
			}
			//_ 다음 문자를 대문자로 바꾸고 _를 지움
			str[i+1] = toupper(c);
			str.erase(i, 1);
		}
	}
	return str;
}
int main() {
	string str;
	cin >> str;
	int type = 0;
	
	//1. c++도 java도 아닌 경우 에러
	if (str.find('_') != string::npos && toLowerCase(str) != str) {
		cout << "Error!";
		return 0;
	}

	//2. 앞 혹은 맨 뒤가 _인 경우 에러
	if (str[0]=='_' || str[str.length() - 1] == '_') {
		cout << "Error!";
		return 0;
	}

	//3. 앞글자가 대문자인 경우 에러
	if (isupper(str[0])) {
		cout << "Error!";
		return 0;
	}
	if (str.find('_') != string::npos) {
		cout << toJava(str);
	}
	else {
		cout << toCpp(str);
	}
	
}
