#include <iostream>
#include <vector>
using namespace std;
int main() {
	int R, B;
	cin >> R >> B;
	int L=0, W=0;
	//L*W=R+B, (L-2)(W-2)=B
	int area = R + B;
	while (L <= area) {
		W++;
		if (area % W == 0) {
			L = area / W;
		}
		if ((L - 2) * (W - 2) == B) break;
	}
	cout << L << " " << W;
}
