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
constexpr ll MAX = 66; // SET MAX SIZE
constexpr ll MOD = 998244353;
i128 sum[MAX][MAX], cnt[MAX][MAX];

void init(){
    cnt[0][0] = 1;
    for(ll i = 0;i <= 60;i++){
        for(int j = 0;j <= i;j++){
            cnt[i + 1][j + 1] += cnt[i][j];
            sum[i + 1][j + 1] += sum[i][j];
            cnt[i + 1][j + 1] %= MOD;
            sum[i + 1][j + 1] %= MOD;

            sum[i + 1][j + 1] += cnt[i][j] * (1ll << i);
            sum[i + 1][j + 1] %= MOD;

            cnt[i + 1][j] += cnt[i][j];
            sum[i + 1][j] += sum[i][j];
            cnt[i + 1][j] %= MOD;
            sum[i + 1][j] %= MOD;
        }
    }
}

ll solve(ll cur, ll num){
    i128 use = 0, ret = 0, mul = 0;
    for(ll i = 60;i >= 0;i--){
        if(!((1ll << i) & cur)) continue;
        if(use <= num){
            ret += sum[i][num - use];
            ret %= MOD;

            ret += (mul * cnt[i][num - use]) % MOD;
            ret %= MOD;
        }

        use++;
        mul += (1ll << i);
        mul %= MOD;
    }

    if(use == num) ret += mul;
    return (ll)(ret %= MOD);
}

void run(){
    cin >> n >> m; 
    cout << solve(n, m) << '\n';
}

int main() {
    fastio; cin >> t; init();
    while(t--) run(); 

    return 0;
}

