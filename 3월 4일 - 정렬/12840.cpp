#include <iostream>
using namespace std;	
#define TIME 86400
int main() {
  //이 세줄 안써줬더니 시간초과 떴다..^^
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, m, s, q, c,T;
	cin >> h >> m >> s;
	cin >> q;
	int current = h * 3600 + m * 60 + s;
	for (int i = 0; i < q; i++) {
		cin >> T;
		if (T == 3) {
			
			cout << current/3600 <<" "<< (current/60)%60<< " " << current%60 << "\n";
		}
		else {
			cin >> c;
			if (T == 1) {
				current = (current + c)% TIME;
			}
			else if (T == 2) {
				current = (current - c) % TIME;
				if (current < 0) current+= TIME;
			}
		}
	}
}
