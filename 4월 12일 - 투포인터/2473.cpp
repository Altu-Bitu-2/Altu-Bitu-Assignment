#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
const long long INF = 3e9 + 1;
tuple<int, int, int> findLiquid(vector<long long>&liquid, int N) {
	tuple <int, int, int> answer;
	long long min_diff = INF;
	for (int i = 0; i < N-2; i++) {
		//하나를 고정시키고 남은 용액들을 투포인터를 사용해서 탐색하면 됨
		long long sum = liquid[i];
		int left = i + 1;
		int right = N - 1;
		while (left < right) {
			sum += liquid[left] + liquid[right];
			//합이 0이면 바로 리턴
			if (sum == 0) {
				return { liquid[i], liquid[left], liquid[right] };
			}
			//합의 절대값이 더 작아진다면 min_diff 값 및 정답 갱신
			if (abs(sum) < min_diff) {
				min_diff = abs(sum);
				answer = { liquid[i], liquid[left], liquid[right] };
			}
      //합이 0보다 크다면 right 값을 줄여서 합을 작게, 합이 0보다 크다면 left값을 키워 합을 크게 만들어야 함
			if (sum > 0) right--;
			else left++;
			sum = liquid[i];
		}
	}
	return answer;
}
int main() {
	int N;
	cin >> N;
	vector<long long>liquid(N);
	for (int i = 0; i < N; i++) {
		cin >> liquid[i];
	}
	sort(liquid.begin(), liquid.end());
	tuple <int, int, int> answer = findLiquid(liquid, N);
	cout << get<0>(answer) <<" " << get<1>(answer) << " " << get<2>(answer);
}
