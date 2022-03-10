#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int>file;

    for (int i = 0; i < N; i++) {
        string filename;
        cin >> filename;
        filename.erase(0, filename.find('.') + 1);
        if (file.find(filename) == file.end()) {
            file.insert(make_pair(filename, 1));
        }
        else {
            file[filename] += 1;
        }
    }
    for (auto iter : file) {
        cout << iter.first << " " << iter.second << "\n";
    }
}
