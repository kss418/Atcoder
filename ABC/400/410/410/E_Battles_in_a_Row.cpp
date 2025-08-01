#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][MAX];
pll a[MAX];

ll solve(ll cur, ll use){
    ll& ret = dp[cur][use];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = (use ? INF : 0);

    if(use) ret = min(ret, solve(cur, use - 1));
    if(use >= a[cur].x) ret = min(ret, solve(cur - 1, use - a[cur].x));
    ret = min(ret, solve(cur - 1, use) + a[cur].y);

    return ret;
}

void run(){
    cin >> n >> m >> k; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    ll result = 0;
    for(int i = 1;i <= n;i++){
        if(solve(i, m) <= k) result = max<ll>(result, i);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

