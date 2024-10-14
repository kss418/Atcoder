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
constexpr ll MAX = 18;
constexpr ll MOD = 998244353;
ll x[MAX], y[MAX];
ld dp[MAX][1ll << MAX];
ll en;

ld dist(ll x1, ll y1, ll x2, ll y2, ld sp){
    ll dx = x1 - x2, dy = y1 - y2;
    ld d = sqrt(dx * dx + dy * dy);
    return d / sp;
}

ld solve(ll cur, ll v){
    ld& ret = dp[cur][v];
    if(ret > -0.5) return ret;
    ll sp = 1;
    for(ll i = 0;i < m;i++) if(v & (1ll << i)) sp <<= 1;

    if((v & en) == en) {
        return ret = dist(0, 0, x[cur], y[cur], sp);
    }

    ret = 1e12;
    for(ll i = 0;i < n + m;i++){
        if(v & (1ll << i)) continue;
        ld now = solve(i, v | (1ll << i)) + dist(x[cur], y[cur], x[i], y[i], sp);
        ret = min(ret, now);
    }

    return ret;
}

int main() {
    fastio;

    cin >> n >> m; en = ((1ll << (n + 1)) - 1) << m;
    for(int i = m;i < n + m;i++) cin >> x[i] >> y[i];
    for(int i = 0;i < m;i++) cin >> x[i] >> y[i];
    memset(dp, -1, sizeof(dp));
    ld result = 1e12;

    cout.precision(20);
    cout << solve(n + m, 1ll << (n + m));


    return 0;
}
