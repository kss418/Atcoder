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

map <ll, long double> dp;
ll a, x, y;

long double solve(ll cur){
    if(dp.count(cur)) return dp[cur];

    long double pre = x + solve(cur / a);
    long double nxt = (6 * y) / (long double)5;
    long double sum = 0;
    for(int i = 2;i <= 6;i++) sum += solve(cur / i);
    nxt += sum / (long double)5;

    dp[cur] = min(pre, nxt);
    return dp[cur];
}

int main() {
    fastio;

    cin >> n >> a >> x >> y;
    dp[0] = 0;

    cout.precision(30);
    cout << solve(n);


    return 0;
}
