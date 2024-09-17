#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> y >> x;
	int arr[1001] = {};
	for (int i = 0; i < y; i++) {
		string ch;
		cin >> ch;
		for (int j = 0; j < ch.size(); j++) {
			if (ch[j] == '#') {
				arr[j]++;
			}
		}
	}

	for (int i = 0; i < x; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}


