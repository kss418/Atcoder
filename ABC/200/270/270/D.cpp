#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][2], a[101];

ll solve(ll cur, ll t){
    ll& ret = dp[cur][t];
    if(ret != -1) return ret;
    ret = (t ? INF : 0);

    for(int i = 1;i <= m;i++){
        if(a[i] > cur) break;
        if(t) ret = min(ret, solve(cur - a[i], t ^ 1));
        else ret = max(ret, solve(cur - a[i], t ^ 1) + a[i]);
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= m;i++) cin >> a[i];
    dp[0][0] = dp[0][1] = 0;

    cout << solve(n, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
