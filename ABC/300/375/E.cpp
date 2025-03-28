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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], sum[4], all;
ll dp[MAX][600][600];

ll solve(ll cur, ll as, ll bs){
    if(cur < 0) return INF;
    if(as < 0 || bs < 0) return INF;
    ll& ret = dp[cur][as][bs];
    if(ret != -1) return ret;
    ret = INF;

    ll da = solve(cur - 1, as - b[cur] ,bs) + 1;
    ll db = solve(cur - 1, as, bs - b[cur]) + 1;
    ll dc = solve(cur - 1, as, bs) + 1;

    if(a[cur] == 1) da--; else if(a[cur] == 2) db--; else dc--;
    ret = min({da, db, dc});
    return ret;
 }

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        sum[a[i]] += b[i];
        all += b[i];
    }

    if(all % 3){
        cout << -1; return 0;
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0; 
    ll result = solve(n, all / 3, all / 3);
    
    if(result >= INF) cout << -1;
    else cout << result;
    

    return 0;
}
