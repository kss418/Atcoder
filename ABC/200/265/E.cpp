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
constexpr ll MAX = 301;
constexpr ll MOD = 998244353;
pll pl[4];
map <pll, bool> ban;
ll dp[MAX][MAX][MAX];


ll solve(ll cur, ll a, ll b){
    ll& ret = dp[cur][a][b];
    if(ret != -1) return ret;
    ll c = cur - a - b; 

    ll cx = pl[1].x * a + pl[2].x * b + pl[3].x * c;
    ll cy = pl[1].y * a + pl[2].y * b + pl[3].y * c;

    if(ban.count({cy, cx})) return ret = 0;
    if(cur == n) return ret = 1;    
    ret = 0;

    ret += solve(cur + 1, a + 1, b); ret %= MOD;
    ret += solve(cur + 1, a, b + 1); ret %= MOD;
    ret += solve(cur + 1, a, b); ret %=MOD;

    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    for(ll i = 1;i <= 3;i++) cin >> pl[i].x >> pl[i].y;

    while(m--){
        ll x, y; cin >> x >> y;
        ban[{y, x}] = 1;
    }
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, 0);

    
    return 0;
}
