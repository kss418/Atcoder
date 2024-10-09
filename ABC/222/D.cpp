#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 3010;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], dp[MAX][MAX];

ll solve(ll cur, ll mx){
    if(cur == 0) return 1;
    if(mx < a[cur]) return 0;
    ll& ret = dp[cur][mx];
    if(ret != -1) return ret;
    ret = 0;

    ret += solve(cur, mx - 1) % MOD;
    ret += solve(cur - 1, min(mx, b[cur - 1]));
    return ret;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    memset(dp, -1, sizeof(dp));
    a[n + 1] = b[n + 1] = 3000;
    cout << solve(n + 1, 3000) % MOD;


    return 0;
}
