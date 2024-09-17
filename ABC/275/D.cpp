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
const int MAX = 101010101;
int dp[MAX];

ll dfs(ll cur) {
	if (cur == 0) {
		return dp[cur] = 1;
	}

	if (cur < MAX && dp[cur] != 0) {
		return dp[cur];
	}

	if (cur < MAX) {
		return dp[cur] = dfs(cur / 2) + dfs(cur / 3);
	}

	return dfs(cur / 2) + dfs(cur / 3);
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	cout << dfs(n);
	

	return 0;
}
