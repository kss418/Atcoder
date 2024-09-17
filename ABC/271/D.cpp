#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, s, f, b;
int fr[101], ba[101];
int dp[101][10001] = { 0, };
char pri[101];
char back[101][10001];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> fr[i] >> ba[i];
	}

	dp[0][0] = 1;
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i <= 10000; i++) {
			if (fr[j - 1] <= i) {
				dp[j][i] = dp[j - 1][i - fr[j - 1]];
				if (dp[j][i] == 1) {
					back[j][i] = 'H';
					continue;
				}
			}
			if (ba[j - 1] <= i) {
				dp[j][i] = dp[j - 1][i - ba[j - 1]];
				if (dp[j][i] == 1) {
					back[j][i] = 'T';
				}
			}
		}
	}

	int loc = s;
	if (dp[n][s] == 1) {
		cout << "Yes" << "\n";
		for (int i = n; i >= 1; i--) {
			if (back[i][loc] == 'H') {
				pri[i] = 'H';
				loc -= fr[i - 1];
			}
			else {
				pri[i] = 'T';
				loc -= ba[i - 1];
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << pri[i];
		}
	}
	else {
		cout << "No";
	}

	return 0;
}
