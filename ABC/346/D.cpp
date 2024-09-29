#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll c[MAX], dp[MAX][2][2];

int main() {
    fastio;

    cin >> n >> s;
    for(int i = 1;i <= n;i++) cin >> c[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][s[0] - '0'][0] = 0; dp[1][(s[0] - '0') ^ 1][0] = c[1];

    for(int i = 2;i <= n;i++){
        ll cur = s[i - 1] - '0';
        dp[i][cur][0] = dp[i - 1][cur ^ 1][0];
        dp[i][cur ^ 1][0] = dp[i - 1][cur][0] + c[i];

        dp[i][cur][1] = min(dp[i - 1][cur ^ 1][1], dp[i - 1][cur][0]);
        dp[i][cur ^ 1][1] = min(dp[i - 1][cur][1], dp[i - 1][cur ^ 1][0]) + c[i];
    }

    cout << min(dp[n][0][1], dp[n][1][1]);


    return 0;
}
