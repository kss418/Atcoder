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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX][MAX], dp[MAX][MAX];

ll solve(ll cur, ll cnt){
    if(cur == -1) return (cnt ? INF : 0);
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = INF;

    for(int i = 0;i < m;i++){
        ret = min(ret, solve(cur - 1, (cnt - i + m) % m) + sum[cur][i]);
    }

    return ret;
}

void run(){
    cin >> n >> m >> k; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++){
        for(int j = 0;j < m;j++){
            sum[i % k][j] += (j - a[i] % m + m) % m;
        }
    }

    cout << solve(k - 1, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}