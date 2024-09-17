#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll dp[MAX][3];

int main()
{
    cin >> n >> s;

    reverse(s.begin(), s.end());
    if (s[0] == 'R') dp[0][2] = 1;
    else if (s[0] == 'S') dp[0][0] = 1;
    else dp[0][1] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);

        if (s[i] == 'R') dp[i][2]++, dp[i][1] = -INF;
        else if (s[i] == 'S') dp[i][0]++, dp[i][2] = -INF;
        else dp[i][1]++, dp[i][0] = -INF;
    }

    cout << max({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] });

  
    return 0;
}
