#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;


const int MAX = 5010;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	
	for (int i = 1; i < n; i++) {
		int cur = n - i;
		for (int j = 0; j < n; j++) {
			if (i + j >= n) {
				break;
			}

			if (s[j] == s[i + j]) {
				cur = j;
				break;
			}
		}
		cout << cur << "\n";
	}
	


	return 0;
}
