#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const int MAX = 1010;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string r;
	cin >> s >> r;
	int flag = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < r.size(); j++) {
			if (s[i + j] == r[j]) {
				if (j == r.size() - 1) {
					flag = 1;
					break;
				}
			}
			else {
				break;
			}
		}
	}

	if (flag) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	


	return 0;
}
