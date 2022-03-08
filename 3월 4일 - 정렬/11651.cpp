#include <iostream>
#include <vector>
#include <algorithm>
typedef pair<int, int> int_pair;
using namespace std;	
bool cmp(const int_pair &a, const int_pair&b) {
	if (a.second == b.second) 
		return a.first < b.first;
	return a.second < b.second;
}
int main() {
	int N;
	cin >> N;
	vector<int_pair> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout<< arr[i].first <<" "<< arr[i].second << "\n";
	}
}
