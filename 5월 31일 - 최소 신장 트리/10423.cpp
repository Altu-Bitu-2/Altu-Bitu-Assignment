
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int INF=1e4+1;

int prim(int n, vector<int> &power, vector<vector<pi>> &graph) {
    priority_queue<pi, vector<pi>, greater<>> pq;
    vector<bool> visited(n+1, false);
    
    int sum=0;
    
    //발전소가 있는 도시와 연결된 경우를 priority queue에 삽입
    for (int i=0; i<power.size(); i++) {
        int current=power[i];
        visited[current]=true;
        for (int j=0; j<graph[current].size(); j++) {
            auto [cost, city]=graph[current][j];
            pq.push({cost, city});
        }
    }
    
    while (!pq.empty()) {
        auto [current_weight, current]=pq.top();
        pq.pop();
        if (visited[current]) continue; 
        visited[current]=true;
        sum+=current_weight;
        
        for (auto[next_weight, next]:graph[current]) {
            if (!visited[next]) {
                pq.push({next_weight, next});
            }
        }
    }
    return sum;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>power(k);
    vector<vector<pi>> graph(n+1, vector<pi>(0));
    //발전소
    for (int i=0; i<k; i++) {
        cin >> power[i];
    }
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b>> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cout<< prim(n, power, graph);
}
