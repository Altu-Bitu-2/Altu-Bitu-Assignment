#include <string>
#include <vector>
#include <iostream>
using namespace std;
int maxDiff=-1;
vector<int> answer;
//라이언과 어피치의 점수를 계산해서 편차를 리턴하는 함수
int calcScore(vector<int>&apeach, vector<int>&ryan) {
    int ryan_score=0;
    int apeach_score=0;
    
    for (int i=0; i<10; i++) {
        if (apeach[i]==0 && ryan[i]==0) continue;
        if (ryan[i]>apeach[i]) ryan_score+=(10-i);
        else apeach_score+=(10-i);
    }
    
    if (apeach_score>=ryan_score) return -1;
    else return ryan_score-apeach_score;
}

//같은 차이에서 더 작은 점수에 더 많은 화살이 있는지 확인
bool isLower(vector<int>&ryan){
    for (int i=10; i>=0; i--) {
        if (ryan[i]<answer[i]) return false;
        if (ryan[i]>answer[i]) return true;
    }
    return false;
}

void solve(vector<int> &apeach, vector<int> &ryan, int index, int arrows) {
    if (index==11 || arrows==0){
        //점수 계산
        int diff=calcScore(apeach, ryan);
        //어피치가 이겼으면x
        if (diff==-1) return;
        //가장 낮은 점수에 화살 몰아줌
        ryan[10]+=arrows;
        //이전에 구한것과 차이가 같은데 더 작은 점수에 화살이 더 많다면 정답 갱신
        if (diff==maxDiff && isLower(ryan)) {
            answer=ryan;
        }
        else if (diff>maxDiff) {
            maxDiff=diff;
            answer=ryan;
        }
        ryan[10]-=arrows;
        return;
    }
    //해당 점수를 가져가는 경우
    if (arrows>apeach[index]) {
        ryan[index]=apeach[index]+1;
        solve(apeach, ryan, index+1, arrows-ryan[index]);
        ryan[index]=0;
    }
    //해당 점수를 안가져가는 경우
    solve(apeach, ryan, index+1, arrows);
}
vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11,0);
    solve(info, ryan, 0, n);
    if (maxDiff==-1) answer.push_back(-1);
    return answer;
}
