#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			cout << i + 1;
			return 0;
		}
	}
	
	cout << s.size() + 1;

	return 0;
}

