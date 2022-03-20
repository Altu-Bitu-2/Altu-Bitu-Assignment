#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
vector<bool>is_prime(1000001, true);
vector<int> prime;
//에라토스테네스의 체를 사용해서 MAX까지의 소수를 구함
void getPrime() {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				if (!is_prime[j]) continue;
				is_prime[j] = false;
			}
		}
	}
}
//n보다 작은 소수중에 최대값의 index값 리턴
int getBiggestPrime(int n) {
	if (n == MAX) return prime.size() - 1;
	for (int i = 1; i < prime.size(); i++) {
		if (n < prime[i]) {
			return i-1;
			break;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	//시간초과 났던 부분
	//while문 돌 때마다 소수를 구하면 시간초과가 나기 때문에 한 번에 MAX값까지 구해줘야함
	getPrime();
	for (int i = 2; i <= MAX; i++) {
		if (is_prime[i]) prime.push_back(i);
	}
	int n = 0;
	while (true) {
		cin >> n;
		if (n == 0) break;
		int left = 0;
		int right = getBiggestPrime(n);
		while (left <= right) {
			if (prime[left] + prime[right] == n) {
				break;
			}
			else if (prime[left] + prime[right] > n) right--;
			else left++;
		}
		if (left > right) cout << "Goldbach's conjecture is wrong.";
		else cout << n <<" = "<< prime[left] << " + " <<prime[right]<<"\n";
	}
}

