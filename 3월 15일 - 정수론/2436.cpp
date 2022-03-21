#include <iostream>
using namespace std;
int gcdRecursion(int a, int b) {
	if (b == 0) return a;
	return gcdRecursion(b, a % b);
}
int main() {
	int gcd, lcm;
	cin >> gcd >> lcm;
	int N = lcm / gcd;
	//cout << n;
	//a*b=n이 되는 (a,b) 쌍 중에서 a와 b가 서로소인 쌍을 찾아야함
	
	//약수 구하기
	//어차피 1*30이나 30*1이나 같으니 루트n까지만 탐색
	long long A = 0, B = 0;
	pair<int, int>answer;
	long long sum = 0;
	for (long long i = 1; i * i <= N; i++) {
		if (N % i == 0 && gcdRecursion(max(i, N/i), min(i,N/i))==1) {
			A = gcd * i;
			B = gcd * (N / i);
		}
	}
	cout << A <<' ' << B;
}

