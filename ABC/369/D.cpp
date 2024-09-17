#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];
ll dp[MAX][2];

int main() {
    fastio;
    cin >> n;
    dp[0][1] = -INF;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j % 2) dp[i][j] = max(dp[i][j], dp[i - 1][j ^ 1] + arr[i]);
            else dp[i][j] = max(dp[i][j], dp[i - 1][j ^ 1] + 2 * arr[i]);     
        }
    }
    
    cout << max(dp[n][0], dp[n][1]);

    return 0;
}
