#include <iostream>
#include <map>
using namespace std;		
map<string, int> m;
void insert() {
	//�̹� �����Ѵٸ� ����, �������� ������ ����
	if (m.find(type) != m.end()) {
		m[type] += 1;
	}
	else {
		m.insert(make_pair(type, 1));
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			string clothes;
			string type;
			cin >> clothes >> type;
		}
		int answer = 1;
		for (auto iter : m) {
			answer *= iter.second + 1;
		}
		//���� ������ ��� ��
		cout << answer - 1 << "\n";
	}

}
