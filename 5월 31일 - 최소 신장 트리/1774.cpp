#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;
typedef tuple<double, int, int> tp;
typedef pair<int, int> pi;
vector<int> parent;

int findParent(int x){
    if (parent[x]<0) return x;
    return parent[x]=findParent(parent[x]);
}

bool unionNodes(int x, int y){
    int px=findParent(x);
    int py=findParent(y);
    
    if (px==py) return false;
    if (parent[px] < parent[py]) {
        parent[px]+=parent[py];
        parent[py]=px;
    }
    else {
        parent[py]+=parent[px];
        parent[px]=py;
    }
    return true;
}

double kruskal(int n, vector<tp> edge) {
    double sum=0;
    int cnt=0;
    
    for (auto [w, a, b]:edge) {
        if (!unionNodes(a, b)) continue;
        sum+=w;
        cnt++;
        if (cnt==n-1) return sum;
    }
    return 0;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<tp> edge;
    vector<pi> space;
    parent.assign(n, -1);
    
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j=0; j<i; j++) {
            double dx=x-space[j].first;
            double dy=y-space[j].second;
            double dist=sqrt(dx*dx+dy*dy);
            edge.push_back({dist, i, j});
        }
        space.push_back({x, y});
    }
    //이미 연결된 경우
    int cnt=0;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if (unionNodes(a-1, b-1)) cnt++;
    }
    sort(edge.begin(), edge.end());
    cout << fixed;
    cout.precision(2);
    cout << kruskal(n-cnt, edge);
}
