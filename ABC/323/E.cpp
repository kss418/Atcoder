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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][10101], sum[10101];

class _inv {
public:
    _inv() {}
    ll pow_mod(ll a, ll b, ll c) {
        if (!b) return 1;
        ll ret = pow_mod(a, b / 2, c) % c;

        if (b % 2) return ((ret * ret) % c * (a % c)) % c;
        return (ret * ret) % c;
    }

    ll prime_inv(ll a, ll b) {
        return pow_mod(a, b - 2, b);
    }

    ll ret(ll a, ll b, ll m) { // (a * b^-1) % m 반환 m == prime
        return (a % m * prime_inv(b, m) % m) % m;
    }
};


void run(){
    cin >> n >> m; _inv inv; ll mul = inv.ret(1, n, MOD);
    for(int i = 1;i <= n;i++) cin >> a[i];

    sum[0] = 1;
    for(int i = 0;i <= m;i++){
        for(int j = 1;j <= n;j++){
            dp[j][i] = (sum[i] * mul) % MOD;
            if(i + a[j] <= m){
                sum[i + a[j]] += dp[j][i];
                sum[i + a[j]] %= MOD;
            }
        }
    }

    ll result = 0;
    for(int i = m;i > m - a[1];i--){
        if(i < 0) break;
        result += dp[1][i];
        result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
