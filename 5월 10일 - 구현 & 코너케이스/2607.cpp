#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;	
void countFrequency(int arr[26], string words) {
	for (int i = 0; i < words.length(); i++) {
		arr[words[i] - 'A']+=1;
	}
}
int main() {
	int N;
	cin >> N;
	vector<string> words(N + 1);
	int frequency[26] = { 0, };

	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}
	countFrequency(frequency, words[0]);
	int answer = 0;
	for (int i = 1; i < N; i++) {
		int cnt = 0;	
		int cmpFrequency[26] = { 0, };
		countFrequency(cmpFrequency, words[i]);
		for (int j = 0; j < 26; j++) {
			cnt += abs(cmpFrequency[j] - frequency[j]);
		}
		if (cnt <= 1 || (cnt == 2 && words[0].length() == words[i].length())) 
			answer++;
	}
	
	cout << answer;
}
