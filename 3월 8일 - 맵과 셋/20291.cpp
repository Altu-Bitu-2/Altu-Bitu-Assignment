#include <iostream>
#include <map>
using namespace std;
map<string, int>file;
void insert(string filename) {
    //기존에 존재하지 않으면 삽입, 존재한다면 개수 증가
    if (file.find(filename) == file.end()) {
        file.insert(make_pair(filename, 1));
    }
    else {
        file[filename] += 1;
    }
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string filename;
        cin >> filename;
        //확장자만 분리
        filename.erase(0, filename.find('.') + 1);
        insert(filename);
    }
    for (auto iter : file) {
        cout << iter.first << " " << iter.second << "\n";
    }
}
