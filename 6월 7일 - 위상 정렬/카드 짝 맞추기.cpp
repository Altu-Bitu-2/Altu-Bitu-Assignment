#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int> pi;
const int INF=10000;
vector<int> cards; //카드 종류를 담는 배열
vector<vector<pi>> location(7); //카드의 위치를 담는 배열
    
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
int answer=INF;

bool isReachable(int x, int y) {
    if (x<0 || x>=4 || y<0 || y>=4) return false;
    return true;
}

int getDist(vector<vector<int>> &board, int r, int c, int x, int y) {
    //(r,c)에서 (x,y) 까지의 최단 경로를 찾아야 함
    vector<vector<int>> dist (4, vector<int>(4, INF));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>pq;
    
    //dist, x, y
    pq.push({0, r, c});
    dist[r][c]=0;
    
    while (!pq.empty()) {
        auto [d, current_r, current_c]=pq.top();
        pq.pop();
        
        if (current_r==x && current_c==y) return d;
        
        for (int i=0; i<4; i++) {
            int next_r=current_r+dx[i];
            int next_c=current_c+dy[i];
            
            if (!isReachable(next_r, next_c)) continue;
            
            //ctrl 없이 이동
            if (dist[next_r][next_c]>d+1) {
                dist[next_r][next_c]=d+1;
                pq.push({d+1, next_r, next_c});
            }
            
            //ctrl 사용
            while (true) {
                //벽에 도달하거나 가장 가까운 카드에 도착했을 때
                if (!isReachable(next_r+dx[i], next_c+dy[i]) || board[next_r][next_c]!=0) break;
                next_r+=dx[i];
                next_c+=dy[i];
            }
            
            if (dist[next_r][next_c]>d+1) {
                dist[next_r][next_c]=d+1;
                pq.push({d+1, next_r, next_c});
            }
        }
    }
    return 0;
}

//백트래킹
void solve(vector<vector<int>> &board, int r, int c, int dist, int cnt){
    if (cnt==cards.size()) {
        dist+=cards.size()*2; //엔터 누르는 횟수
        answer=min(answer, dist);
        return;
    }
    
    //target card
    int card_num=cards[cnt];
    //카드의 위치
    vector<pi> cur_location=location[card_num];
    //현재 지점부터 0번 카드->1번 카드 vs 현재 지점부터 1번 카드->0번 카드까지
    int dist_zero=getDist(board, r, c, cur_location[0].first, cur_location[0].second)+getDist(board, cur_location[0].first, cur_location[0].second,cur_location[1].first, cur_location[1].second);
    int dist_one=getDist(board, r, c, cur_location[1].first, cur_location[1].second)+getDist(board, cur_location[1].first, cur_location[1].second, cur_location[0].first, cur_location[0].second);

    //카드 없애기
    board[cur_location[0].first][cur_location[0].second]=0;
    board[cur_location[1].first][cur_location[1].second]=0;
    
    //현재위치, 거리, 횟수 갱신
    solve(board, cur_location[1].first, cur_location[1].second, dist+dist_zero, cnt+1);
    solve(board, cur_location[0].first, cur_location[0].second, dist+dist_one, cnt+1);
    
    //보드 원위치
    board[cur_location[0].first][cur_location[0].second]=card_num;
    board[cur_location[1].first][cur_location[1].second]=card_num;
}

int solution(vector<vector<int>> board, int r, int c) {
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[i].size(); j++) {
            if (board[i][j]>0) {
                cards.push_back(board[i][j]);
                location[board[i][j]].push_back({i,j});
            }
        }
    }
    
    //중복된 카드 제거
    sort(cards.begin(), cards.end());
    cards.erase(unique(cards.begin(), cards.end()), cards.end());
    
    //카드 순서: 순열
    do{
        solve(board, r, c, 0, 0);
    }while(next_permutation(cards.begin(), cards.end()));
    
    return answer;
}
