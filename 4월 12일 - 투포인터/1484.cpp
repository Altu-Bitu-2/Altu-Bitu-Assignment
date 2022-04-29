#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int G;
	cin >> G;
	//현재 몸무게+기억하는 몸무게=right
	//현재 몸무게-기억하는 몸무게=left
	//G=a*b
	int left = 1;
	int right = G;
	vector<int>answer;
	while (left < right) {
		if (left * right == G) {
			//몸무게는 자연수여야함
			if ((left + right) % 2 == 0) {
				answer.push_back((left + right) / 2);
			}
			left++;
		}
		else if (left * right > G) {
			right--;
		}
		else {
			left++;
		}
	}
	if (answer.empty()) {
		cout << -1;
		return 0;
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}
