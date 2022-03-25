#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector <bool> init(int L, int C) {
	vector <bool> arr(C, false);
	for (int i = 0; i < L; i++) {
		arr[i] = true;
	}
	return arr;
}
vector<string> createPassword(int L, int C, vector<char> &alphabet) {
	vector<string> answer;
	char vowel[5] = { 'a','e','i','o','u' };
	vector <bool> temp = init(L, C);
	do {	
		string password;
		int vowel_cnt = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i]) password += alphabet[i];
		}
		for (int j = 0; j < 5; j++) {
			if (password.find(vowel[j]) != string::npos) {
				vowel_cnt++;
			}
		}
		if (vowel_cnt >= 1 && L - vowel_cnt >= 2) {
			sort(password.begin(), password.end());
			answer.push_back(password);
		}
	} while (prev_permutation(temp.begin(), temp.end()));
	return answer;
}
int main() {
	int L, C;
	cin >> L >> C;
	vector<char> alphabet(C);
	vector<string> answer;
	for (int i = 0; i < C; i++) {
		cin >> alphabet[i];
	}
	answer = createPassword(L, C, alphabet);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i]<<"\n";
	}
}
