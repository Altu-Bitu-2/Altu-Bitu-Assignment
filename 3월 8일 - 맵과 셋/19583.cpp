#include <iostream>
#include <set>
using namespace std;

int main()
{
    string S, E, Q;
    set<string>students;
    set<string> s;
    cin >> S >> E >> Q;
    while (!cin.eof()) {
        string chat_time;
        string name;
        cin >> chat_time >> name;
        //개강총회 시작 전에 입장한 사람 체크
        if (chat_time <= S) {
            students.insert(name);
        }
        //개강총회 끝~스트리밍 끝 사이에 채팅 남긴사람 중 시작전에 채팅 남긴 사람
        if (chat_time >=E && chat_time<= Q && students.find(name)!=students.end()) {
            s.insert(name);
        }
    }
    cout << s.size();

}
