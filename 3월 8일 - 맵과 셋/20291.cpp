#include <iostream>
#include <map>
using namespace std;
map<string, int>file;
void insert(string filename) {
    //������ �������� ������ ����, �����Ѵٸ� ���� ����
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
        //Ȯ���ڸ� �и�
        filename.erase(0, filename.find('.') + 1);
        insert(filename);
    }
    for (auto iter : file) {
        cout << iter.first << " " << iter.second << "\n";
    }
}
