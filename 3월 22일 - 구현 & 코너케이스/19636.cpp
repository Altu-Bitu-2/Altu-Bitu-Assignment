#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	//현재 체중, 일일 에너지 섭취량==기초대사량, 기초대사량 변화 역치
	//10000, 1500, 500
	int w, e, t;
	//다이어트 기간, 다이어트 중 일일 에너지 섭취량, 활동 대사량
	//5, 1000, 700
	int D, L, A;
	cin >> w>>e>>t;
	cin >> D >> L >> A;

	int temp_w = w;
	int temp_e = e;


	while (D--) {
		//1. 기초 대사량의 변화를 고려 X
		w += (L - (e + A));
		//2. 기초 대사량 변화 고려
		//에너지소비량=기초대사량+활동대사량
		int energy = temp_e + A;
		temp_w += (L - energy);
		if (abs(L - energy) > t) {
			temp_e+=floor((L - energy) / 2.0);
		}
	}
	//1. 기초 대사량의 변화를 고려 X
	if (w <= 0) cout << "Danger Diet\n";
	else cout << w << " " << e<<"\n";

	//2. 기초 대사량 변화 고려
	if (temp_w<=0 || temp_e<=0)  cout << "Danger Diet\n";
	else {
		cout << temp_w << " " << temp_e << " ";
		//다이어트 전 일일 활동 대사량으로 돌아갔을 때
		if (e > temp_e) cout << "YOYO";
		else cout << "NO";
	}
}
