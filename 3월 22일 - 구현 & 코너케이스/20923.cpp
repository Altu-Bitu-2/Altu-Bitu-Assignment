#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> player[2];
deque<int> ground[2];
void takeCard(int winner, int loser) {
	//상대꺼 가져오기
	while (!ground[loser].empty()) {
		player[winner].push_back(ground[loser].back());
		ground[loser].pop_back();
	}
	//내꺼 가져오기
	while (!ground[winner].empty()) {
		player[winner].push_back(ground[winner].back());
		ground[winner].pop_back();
	}
}
bool play(int turn) {
	//자신의 그라운드에 카드를 내려놓음
	int card = player[turn].front();
	ground[turn].push_front(card);
	player[turn].pop_front();
	if (player[turn].empty()) return false;
	//카드 숫자 합이 5이면 수연 승
	if (!ground[0].empty() && !ground[1].empty()) {
		if (ground[0].front() + ground[1].front() == 5) {
			takeCard(1, 0);
		}
	}
	//가장 위 카드가 5면 도도 승
	if (card== 5) {
		takeCard(0, 1);
	}
	return true;
}
int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		//처음엔 vector을 따로 선언하려고 했지만 그러면 너무 비효율적인 코드가 나옴
		player[0].push_front(a); //도도
		player[1].push_front(b); //수연
	}

	int turn = 0;
	while (M--) {
		if (!play(turn)) break;
		turn = 1 - turn;
	}

	if (player[0].size() > player[1].size()) cout << "do";
	else if (player[0].size() < player[1].size()) cout << "su";
	else cout << "dosu";
}
