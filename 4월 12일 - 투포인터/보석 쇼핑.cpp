#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    //처음 풀었을 땐 모든 종류의 보석을 담을 수 있는 최대 right를 구하고 left를 줄여주면 된다고 생각했는데 뒤에 가서 더 짧은 구간이 나올 수 있다는 사실을 간과함
    vector<int> answer(2);
    map<string, int> m; //보석 종류, 보석 개수
    for (int i=0; i<gems.size(); i++) {
        m[gems[i]]++;
    }
    //보석 종류 == m.size();
    int total=m.size();
    m.clear();
    
    //0부터 같이 움직이는 투포인터로 구현
    int left=0;
    int right=0;
    //최소 구간 초기화
    int dist=gems.size()+1;
    while (true) {
        //정답 조건: 모든 종류의 보석을 담음
        if (m.size()==total) {
            //구간이 최소일 때 정답 갱신
            if (right-left<dist) {
                dist=right-left;
                answer[0]=left+1;
                answer[1]=right;
            }
            //여기서 헛발질을 했는데 1개만 남았을 때 erase 말고 그냥 마이너스를 해준다면 자리는 계속 차지하기 때문에 지워줘야 한다
            if (m[gems[left]]==1) m.erase(gems[left]);
            else m[gems[left]]--;
            left++;
        }
        else {
            //끝까지 탐색했으면 종료
            if (right==gems.size()) break;
            //모든 종류의 보석을 담지 못했으면 right 증가
            else {
                m[gems[right]]++;
                right++;
            }
        }
    }
    return answer;
}
