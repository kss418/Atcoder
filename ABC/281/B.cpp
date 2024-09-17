#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	if (s.size() != 8) {
		cout << "No";
		return 0;
	}

	if (s[0] < 'A' || s[0] > 'Z') {
		cout << "No";
		return 0;
	}
	
	if (s[7] < 'A' || s[7] > 'Z') {
		cout << "No";
		return 0;
	}

	if (s[1] < '1' || s[1] > '9') {
		cout << "No";
		return 0;
	}

	for (int i = 2; i <= 6; i++) {
		if (s[i] < '0' || s[i] > '9') {
			cout << "No";
			return 0;
		}
	}


	cout << "Yes";

	return 0;
}

