#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int makeScore(int num, vector<bool>&ground) {
	int score = 0;
	for (int i = 2; i >= 0; i--) {
		
		if (!ground[i]) continue; //해당 루에 사람이 없으면 건너 뜀
		ground[i] = false;
		if (i + num > 2) score++;
		else ground[i + num] = true;
	}
	//홈런이면 타자도 득점
	if (num == 4) score++;
	else ground[num-1] = true;
	return score;
}
int main() {
	int N;
	cin >> N;
	vector<vector<int>> team(N, vector<int>(9)); //n이닝 i번째 선수가 칠 수 있는 것
	vector<int> temp = {0, 1, 2, 3, 4, 5, 6, 7, 8 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> team[i][j];
		}
	}
	int answer = 0;
	do {
		//4번째 선수가 1번선수(0)이 아니면 패스
		if (temp[3] != 0) continue;
		//초기화
		int out = 0; //out 개수
		int score = 0; //점수
		int ining = 0; //현재 이닝
		int current = 0; //현재 선수의 인덱스 temp[current]가 현재 선수 번호
		vector<bool> ground(3, false);
		while (true) {
			current %= 9;
			//아웃이 3개면 다음 이닝으로 이동하고 아웃 개수 초기화
			if (out == 3) {
				ining++;
				out = 0;
				//한 이닝이 끝나면 그라운드를 비워줘야 함
				ground.assign(3, false);
			}
			if (ining == N) break;
			if (team[ining][temp[current]] == 0) {
				out++;
				current++;
				continue;
			}
			score+=makeScore(team[ining][temp[current]], ground);
			current++;
		}
		answer = max(answer, score);
	} while (next_permutation(temp.begin(), temp.end()));
	cout << answer;
}
