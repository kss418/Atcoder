#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll; 
using namespace std;
ll dp[100001][5];
ll list[100001][5];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	int time, x, si;
	fill(&dp[0][0], &dp[100000][5], -1);
	dp[0][0] = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time >> x >> si;
		list[time][x] = si;
	}

	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < 5; j++) {
			if (j != 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			}

			if (j != 4) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
			}

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);

			if (dp[i][j] != -1) {
				dp[i][j] += list[i][j];
			}
		}
	}
	
	ll result = 0;
	for (int i = 0; i < 5; i++) {
		result = max(result, dp[100000][i]);
	}

	cout << result;

	return 0;
}

