#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getSum(int N, vector<int> &v) {
	int sum = 1;
	//현재 1~5까지 측정할 수 있다고 할 때 새로운 무게 x가 추가된다면
	//1+x~5+x도 측정이 가능해짐
	//이 때 1+x와 5가 이어지지 않는다면 측정하지 못하는 최소값이 생김
	for (int i = 0; i < N; i++) {
		if (sum < v[i]) break;
		sum += v[i];
	}
	return sum;
}
int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	cout << getSum(N, v);
}
