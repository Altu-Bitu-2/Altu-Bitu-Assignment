#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e5;
vector<int>is_prime(MAX+1);	
map <int, int> m; //소수와 지수
void getPrime() {
	//prime배열을 자기 자신으로 초기화
	for (int i = 2; i <= MAX; i++) {
		is_prime[i] = i;
	}
	for (int i = 2; i * i <= MAX; i++) {
		if (is_prime[i]==i) {
			for (int j = i * i; j <= MAX; j += i) {
				//나누어지는 가장 작은 소수를 저장
				if (is_prime[j] == j) is_prime[j] = i;
			}
		}
	}
}
void factorize(int num, char op) {		
	//만약 6이면 2와 3의 지수가 1개씩 올라가거나 내려감
	while (num > 1) {
		if (op=='*') m[is_prime[num]]++;
		else m[is_prime[num]]--;
		num /= is_prime[num];
	}
}
int main() {
	int N;
	cin >> N;
	int num; char op;
	cin >> num; //가장 첫번째는 앞이 곱하기라고 생각하면 됨
  //이거 예외처리 안해주면 94%에서 틀렸습니다 뜬다..^_^
	if (num == 0) {
		cout << "mint chocolate";
		return 0;
	}
	getPrime();
	factorize(abs(num), '*');
	for (int i= 0; i < N - 1; i++) {
		cin >> op >> num;
		if (num == 0) {
			cout << "mint chocolate";
			return 0;
		}
		if (num == 1) continue;
		factorize(abs(num), op);
	}
	//분자가 존재하면
	for (auto iter : m) {
		if (iter.second < 0) {
			cout << "toothpaste";
			return 0;
		}
	}
	cout << "mint chocolate";

}

