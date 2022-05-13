#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<char> v(N, '?');
	int current = 0;
	int spin; char alphabet;
	for (int i = 0; i < K; i++) {
		cin >> spin >> alphabet;
		//이미 적혀있는 알파벳이 있는데 바뀌려고 할 때 ! 출력
		if (v[(current + spin) % N] != '?' && v[(current + spin) % N] != alphabet) {
			cout << "!";
			return 0;
		}
		v[(current + spin) % N] = alphabet;
		current += spin;
		current %= N;
	}
	//중복되는 알파벳이 있는 경우
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (v[i] == v[j] && v[i] != '?') {
				cout << "!";
				return 0;
			}
		}
	}	
	int temp = N;
	while (temp--) {
		if (current < 0) current = N-1;
		cout << v[current];
		current--;
	}
	
}	
