#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
bool check(set<vector<int>> &s, int x, int y, int a){
    if (s.find({x, y, a})!=s.end()) return true;
    return false;
}
bool isChangable(set<vector<int>> &s) {
    for (auto iter:s) {
        int x=iter[0];
        int y=iter[1];
        int a=iter[2];
        //기둥일 때 
        //기둥이 바닥 or 아래에 기둥이 있을 때 or 설치지점이 보인 경우
        //보는 오른쪽으로 설치되기 때문에 위치가 (x, y) 이거나 (x-1, y)이다
        if (a==0) {
            if (y==0 ||check(s, x, y-1, 0) || check(s, x, y, 1) || check(s, x-1, y, 1)) continue;
            else return false;
        }
        //보 일 때
        //보는 설치지점 바로 아래가 기둥이거나 오른쪽 아래가 기둥이거나 or 양쪽이 보여야 함
        else if (a==1) {
            if (check(s, x, y-1, 0) || check(s, x+1,y-1,0) || (check(s, x-1, y, 1) && check(s, x+1, y, 1))) continue;
            else return false;
        }
    }
    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> s; //삭제와 삽입이 용이한 set 사용
    for (auto building: build_frame) {
       	int x=building[0];
        int y=building[1];
        int a=building[2];
        int b=building[3];
  
        //삭제
        if (b==0) {
            s.erase({x,y,a});
            if (!isChangable(s)) {
                s.insert({x,y,a});
            }
        }
        //설치
        else {
            s.insert({x,y,a});
            if (!isChangable(s)) {
                s.erase({x,y,a});
            }
        }
    }
    for (auto iter: s) {
        answer.push_back(iter);
    }
    return answer;
}
