#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 5010;
constexpr ll MOD = 998244353;
pll arr[MAX];
ll dp[MAX][MAX];
set <ll> num[MAX];

int main() {
    fastio;
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].first;
    for (int i = 1; i <= n; i++) cin >> arr[i].second; 
    sort(arr + 1, arr + n + 1); 

    ll result = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 5000; j++) {
            if (j >= arr[i].second) dp[i][j] = dp[i - 1][j - arr[i].second] % MOD; 
            if (j <= arr[i].first && j) result += dp[i][j] % MOD, result %= MOD;

            dp[i][j] += dp[i - 1][j] % MOD;
            dp[i][j] %= MOD;
        }
    }

    cout << result % MOD;


    return 0;
}
