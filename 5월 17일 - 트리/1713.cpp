#include <iostream>
#include <vector>
#include<algorithm>
#include<map>
using namespace std;
bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
	if (a.second.first == b.second.first) return a.second.second > b.second.second;
	return a.second.first > b.second.first;
}
int main() {
	int n, recom_num;
	cin >> n >> recom_num;
	//학생, 득표수, 걸린 순서
	vector<pair<int, pair<int, int>>> picture(n);
	for (int i = 0; i < recom_num; i++) {
		int student;
		cin >> student;
		bool flag = false;
		//사진틀 먼저 검사하고 중복을 검사하면 중복이 있어도 다른 사진틀에 들어감

		for (int j = 0; j < n; j++) {
			//이미 학생이 존재하거나
			if (picture[j].first == student) {
				picture[j].second.first++;
				flag = true;
				break;
			}
			//사진틀이 비어있는 경우
			if (picture[j].first==0) {
				picture[j].first = student;
				picture[j].second.first = 1;
				picture[j].second.second = i;
				flag = true;
				break;
			}
			
		}
		//한 명을 밀어내고 넣어야하는 경우
		if (!flag) {
			sort(picture.begin(), picture.end(), cmp);
			picture.pop_back();
			picture.push_back(make_pair(student, make_pair(1, i)));
		}

	}
	sort(picture.begin(), picture.end());
	for (int i = 0; i < n; i++) {
		if (picture[i].first == 0) continue;
		cout << picture[i].first << " ";
	}
}
