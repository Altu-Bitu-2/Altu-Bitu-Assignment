#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct emp {
	int d, h, line, i;
};
//비교 구조체
struct cmp {
	bool operator()(const emp& a, const emp& b) {
		if (a.d != b.d) return a.d < b.d;
		if (a.h != b.h) return a.h < b.h;
		return a.line > b.line;
	}
};
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<queue<emp>> lines(M);
	priority_queue<emp, vector<emp>, cmp>pq;
	for (int i = 0; i < N; i++) {
		int d, h;
		cin >> d >> h;
		lines[i % M].push({ d,h,i % M,i });
	}
	//선두 M명을 pq에 집어넣음
	for (int i = 0; i < M; i++) {
		if (!lines[i].empty()) {
			pq.push(lines[i].front());
			lines[i].pop();
		}
	}
	int answer = 0;
	//매번 pq에 넣어주면서 비교해야함
	while (!pq.empty()) {
		//데카 차례가 오면 break
		if (pq.top().i==K) break;
		emp person = pq.top();
		pq.pop();
		answer++;
		//화장실에 들어간 사람의 뒤 사람이 선두로 옴
		if (!lines[person.line].empty()) {
			pq.push(lines[person.line].front());
			lines[person.line].pop();
		}
	}
	cout << answer;
}
