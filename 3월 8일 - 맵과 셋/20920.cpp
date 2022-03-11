#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<string, int> si;
map<string, int>m;
bool cmp(const si& a, const si& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	if (a.first.length() != b.first.length()) {
		return a.first.length() > b.first.length();
	}
	return a.first < b.first;
}
void insert(string word) {
	//기존에 존재하지 않으면 삽입, 존재한다면 개수 증가
	if (m.find(word) != m.end())
		m[word]++;
	else
		m.insert(make_pair(word, 1));
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		//길이가 M이상인 것만 실행
		if (word.length() >= M) {
			insert(word);
		}
	}
	//정렬하기 위해 map을 벡터화
	vector<si> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << "\n";
	}
}
