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
ll n, m, k, t = 1; 

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 9; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll s[MAX], c[MAX], p[MAX];
ld dp[MAX][1 << MAX][5010];
vector <ll> seq;

ld solve(ll cur, ll v, ll cnt){
    ld& ret = dp[cur][v][cnt];
    if(ret >= -0.5) return ret; ret = 0;
    
    for(ll nxt = 1;nxt <= n;nxt++){
        if(v & (1ll << nxt)) continue;
        if(cnt < c[nxt]) continue;
        ld now = solve(nxt, v, cnt - c[nxt]) * (100 - p[nxt]) / 100;
        now += (solve(nxt, v | (1ll << nxt), cnt - c[nxt]) + s[nxt]) * p[nxt] / 100;
        
        ret = max(ret, now);
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -2, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> s[i] >> c[i] >> p[i];

    cout.precision(20);
    cout << solve(0, 1, m);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

