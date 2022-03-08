#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector <pair<int, int>> score(N);
		for (int i = 0; i < N; i++) {
			cin >> score[i].first >> score[i].second;
		}
		sort(score.begin(), score.end());
		int answer = 1;
		int compare = score[0].second;
		for (int i = 1; i < N; i++) {
			if (compare > score[i].second) {
				answer++;
				compare = score[i].second;
			}
		}
		cout << answer << "\n";
	}
}
