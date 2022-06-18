#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calSum(vector<int> &v) {
	int i = 0;
	int sum = 0;
	while (i < v.size()) {
		//만약 두 수를 곱한 것이 합한것보다 크다면 곱을 더하고 인덱스를 2증가
		if (i<v.size() - 1 && v[i] * v[i + 1]>v[i] + v[i + 1]) {
			sum += v[i] * v[i + 1];
			i += 2;
		}
		//아니라면 수 하나만 더하고 인덱스 하나 증가
		else {
			sum += v[i];
			i++;
		}
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	//양수를 담을 벡터와 음수를 담을 벡터를 따로 선언
	vector<int> vp;
	vector<int> vn;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num <= 0) vn.push_back(num);
		else vp.push_back(num);
	}

	//음수는 오름차순, 양수는 내림차순 정렬
	sort(vn.begin(), vn.end());
	sort(vp.begin(), vp.end(), greater<>());
	int sum = 0;
	sum += calSum(vp) + calSum(vn);
	cout << sum;
}
