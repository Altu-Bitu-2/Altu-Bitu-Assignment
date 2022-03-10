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
	//������ �������� ������ ����, �����Ѵٸ� ���� ����
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
		//���̰� M�̻��� �͸� ����
		if (word.length() >= M) {
			insert(word);
		}
	}
	//�����ϱ� ���� map�� ����ȭ
	vector<si> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << "\n";
	}
}
