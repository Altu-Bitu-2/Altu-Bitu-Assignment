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
        //������ȸ ���� ���� ������ ��� üũ
        if (chat_time <= S) {
            students.insert(name);
        }
        //������ȸ ��~��Ʈ���� �� ���̿� ä�� ������ �� �������� ä�� ���� ���
        if (chat_time >=E && chat_time<= Q && students.find(name)!=students.end()) {
            s.insert(name);
        }
    }
    cout << s.size();

}
