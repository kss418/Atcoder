#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll dp[MAX][11];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = 1;

    if(cnt) ret = max(ret, solve(cur - 1, cnt - 1) * a[cur].x + a[cur].y);
    ret = max(ret, solve(cur - 1, cnt));

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    
    sort(a + 1, a + n + 1, [](pll& a, pll& b){
        return b.y * (a.x - 1) < a.y * (b.x - 1);
    });

    cout << solve(n, m);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}