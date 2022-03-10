#include <iostream>
#include <set>
using namespace std;

int main()
{
    string str;
    set<string> s;
    cin >> str;
    for (int i=0; i<=str.length(); i++){
        for (int j=1; j<str.length()-i+1; j++){
            string a=str.substr(i, j);
            s.insert(a);
        }
    }
    cout << s.size();
    
}
