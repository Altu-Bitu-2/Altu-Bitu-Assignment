#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;	
int main() {
	int start, end;
	vector<int> arr(21);
	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cin >> start >> end;
		reverse(arr.begin()+start, arr.begin()+end+1);
	}
	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << " ";
	}
}
