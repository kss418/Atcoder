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
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 121; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX], a[3];

ll solve(ll cur){
    if(cur < 0) return INF;
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = INF;
    ret = min(ret, solve(cur - 6) + a[0]);
    ret = min(ret, solve(cur - 8) + a[1]);
    ret = min(ret, solve(cur - 12) + a[2]);

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp)); dp[0] = 0;
    for(int i = 0;i < 3;i++) cin >> a[i];
    ll result = INF;
    for(int i = n;i < 121;i++) result = min(result, solve(i));
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

