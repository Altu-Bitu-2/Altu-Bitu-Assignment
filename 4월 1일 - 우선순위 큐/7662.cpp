#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pi;
typedef priority_queue<pi> max_pq;
typedef priority_queue<pi, vector<pi>, greater<pi>> min_pq;		
max_pq max_heap;
min_pq min_heap;
vector<bool> visited;
void dualPriorityQueue(int op, int n, int i) {
	if (op == 'I') {
		max_heap.push({ n, i });
		min_heap.push({ n, i });
		visited[i] = true;
	}
	else if (op == 'D') {
		if (n == -1) {
			if (!min_heap.empty()) {
				visited[min_heap.top().second] = false;
				min_heap.pop();
			}
		}
		else if (n == 1) {
			if (!max_heap.empty()) {
				visited[max_heap.top().second] = false;
				max_heap.pop();
			}
		}
	}
	//maxheap과 minheap을 동일하게 맞춤
	while (!max_heap.empty() && !visited[max_heap.top().second]) {
		max_heap.pop();
	}
	while (!min_heap.empty() && !visited[min_heap.top().second]) {
		min_heap.pop();
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		visited.assign(1000001, false);
		//max_heap과 min_heap을 둘 다 만들어서 해당하는 삭제연산을 시행하고 
		//같은 값을 유지할 수 있도록 해주면 됨
		for (int i = 0; i < N; i++) {
			char op; int n;
			cin >> op >> n;
			dualPriorityQueue(op, n, i);
		}
		if (max_heap.empty()) cout << "EMPTY\n";
		else cout << max_heap.top().first << " " << min_heap.top().first << "\n";
	}
}
