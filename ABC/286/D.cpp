#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 51;
int arr[MAX * MAX];
ll dp[MAX * MAX][10101];




int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	int cnt = 1;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = cnt; j < cnt + b; j++) {
			arr[j] = a;
		}
		cnt += b;
	}

	dp[0][0] = 1;
	for (int i = 1; i < cnt; i++) {
		for (int j = 0; j <= m; j++) {
			if (j >= arr[i]) {
				dp[i][j] = max(dp[i - 1][j - arr[i]], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}


	if (dp[cnt - 1][m]) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	

	return 0;
}
