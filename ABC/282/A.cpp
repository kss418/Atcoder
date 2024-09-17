#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	string s;

	cin >> n >> s;
	int a = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '\"') {
			if (a) {
				a = 0;
			}
			else {
				a = 1;
			}
			cout << s[i];
		}
		else if (s[i] == ',') {
			if (a) {
				cout << ",";
			}
			else {
				cout << ".";
			}
		}
		else {
			cout << s[i];
		}
	}
	



	return 0;
}

