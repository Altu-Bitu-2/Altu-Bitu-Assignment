#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>candy;
vector<int>parent;
int findParent(int node) {
    if (parent[node] < 0) return node;
    return parent[node] = findParent(parent[node]);
}

void unionParent(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    //부모가 같을 때도 탐색하면 메모리 초과 
    if (xp == yp) return;
    if (xp < yp) parent[yp] = xp;
    else parent[xp] = yp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    candy.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    //한 번에 빼앗을 수 있는 사람 수, 사탕 수
    vector<pair<int, int>>temp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> candy[i];
        temp[i] = make_pair(1, candy[i]);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        unionParent(x, y);
    }

    for (int i = 1; i <= n; i++) {
        //루트 노드는 건너뜀
        if (parent[i] < 0) continue;

        int p = findParent(i);
        temp[p].first+=1;
        temp[p].second += candy[i];
    }

    //dp[a]=b -> 아이를 a명 선택했을 때 받을 수 있는 사탕의 최대값은 b
    vector<int>dp(k, 0);

    for (int i = 1; i <= n; i++) {
        //루트 노드가 아니라면 탐색x
        if (parent[i] != -1) continue;
        for (int j = k - 1; j>=temp[i].first; j--) {
            dp[j] = max(dp[j], dp[j - temp[i].first] + temp[i].second);
        }
    }

    int answer = 0;
    for (int i = 0; i < k; i++) {
        answer = max(answer, dp[i]);
        //cout << dp[i] << "\n";
    }
    cout << answer;
}


