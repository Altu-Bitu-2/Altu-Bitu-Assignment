#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int x, n;
	cin >> x >> n;

	//화살표가 한개인 경우
	//음수라면 무한루프
	//아니라면 루프를 돌지 않아서 0출력
	if (n == 1) {
		if (x < 0) cout << "INFINITE";
		else cout << 0;
		return 0;
	}

	//화살표가 0개인 경우
	if (n == 0) {
		if (x>0) cout << "INFINITE";
		else cout << 0;
		return 0;
	}

	//화살표가 홀수개라면 에러
	if (n % 2 != 0) {
		cout << "ERROR";
		return 0;
	}
	
	int cnt = n / 2;
	if (x > 0) cout << (x - 1) / cnt;
	else cout << 0;
}
