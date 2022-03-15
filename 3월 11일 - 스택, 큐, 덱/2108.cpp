#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
vector<int> num;
map<int, int> m;
int mean() {
	double sum = 0;
	for (int i = 0; i < num.size();i++) {
		sum += num[i];
	}
	return round(sum / num.size());
}
int median() {
	sort(num.begin(), num.end());
	return num[num.size() / 2];
}
void insertNum(int number) {
	if (m.find(number) != m.end()) {
		m[number]+=1;
	}
	else {
		m.insert(make_pair(number, 1));
	}
}
bool cmp(const pi& a, const pi& b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}
int mode() {
	vector<pi> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	if (v[0].second == v[1].second) return v[1].first;
	else return v[0].first;
}
int range() {
	sort(num.begin(), num.end());
	return num.back() - num.front();
}
int main() {
	int N;
	cin >> N;
	num.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		insertNum(num[i]);
	}
	if (N == 1) {
		cout << num[0] << "\n";
		cout << num[0] << "\n";
		cout << num[0] << "\n";
		cout << 0 << "\n";
	}
	else {
		cout << mean() << "\n";
		cout << median() << "\n";
		cout << mode() << "\n";
		cout << range() << "\n";
	}

}
