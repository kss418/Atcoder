#include <bits/stdc++.h>
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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sz[MAX], b[MAX][MAX];
ld dp[MAX];

ld solve(ll cur){
    if(cur <= 0) return 0;
    ld& ret = dp[cur];
    if(ret > -0.5) return ret; ret = 1e12;

    for(int i = 1;i <= n;i++){
        ld pl = 0; ll cnt = 0;
        for(int j = 1;j <= sz[i];j++){
            if(b[i][j]) pl += solve(cur - b[i][j]);
            else cnt++;
        }

        if(cnt == sz[i]) continue;
        ld now = (a[i] * sz[i] + pl) / (ld)(sz[i] - cnt);
        ret = min(ret, now);
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> sz[i];
        for(int j = 1;j <= sz[i];j++) cin >> b[i][j];
    }

    cout.precision(20);
    cout << solve(m);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}