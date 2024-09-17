#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	
	int result = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a') {
			result = i + 1;
		}
	}

	cout << result;
	




	
	return 0;
}

