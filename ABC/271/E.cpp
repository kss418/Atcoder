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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
tll line[MAX];
ll dp[MAX];

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        ll a, b, c; cin >> a >> b >> c;
        line[i] = {a, b, c};
    }
    memset(dp, 0x3f, sizeof(dp)); dp[1] = 0;

    for(int i = 1;i <= k;i++){
        ll cur; cin >> cur;
        auto [s, e, c] = line[cur];

        dp[e] = min(dp[e], dp[s] + c);
    }

    if(dp[n] >= INF) cout << -1;
    else cout << dp[n];

    
    return 0;
}
