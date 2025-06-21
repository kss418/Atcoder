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
ll sum, a[MAX], result, pre[11];

class _comb{
public:
    vector <ll> fac, inv; ll n, mod;
    _comb(ll n, ll m = 998244353){ // m == MOD && m == prime
        fac.resize(n + 1); inv.resize(n + 1);
        this->mod = m; this->n = n;

        fac[0] = 1; 
        for(int i = 1;i <= n;i++) fac[i] = fac[i - 1] * i % mod;
        inv[n] = pow(fac[n], mod - 2, mod);
        for(int i = n - 1;i >= 0;i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    }

    ll pow(ll a, ll p, ll mod) {
        if (!p) return 1;
        if (p == 1) return a % mod;

        ll cur = pow(a, p / 2, mod);
        cur = cur * cur % mod;
        if (p % 2 == 0) return cur % mod;
        return (cur * a) % mod;
    }

    ll ret(ll n, ll m){ // return nCm
        if(n < 0 || m < 0 || n < m) return 0;
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
};

class _pow {
public:
    _pow() {}

    ll ret(ll a, ll b){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a;
            a *= a; b >>= 1;
        }      
        return ret;
    }

    ll ret(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
};

void run(){
    cin >> n >> m; _comb comb(11); _pow pow;
    for(int i = 1;i <= n;i++) cin >> a[i];

    pre[0] = 1;
    for(int i = 1;i <= n;i++){
        ll now = 0; sum += a[i]; sum %= MOD;

        for(int j = 0;j <= m;j++){
            ll c = comb.ret(m, j), sr = pow.ret(sum, m - j, MOD);
            now += (c * sr) % MOD * pre[j] % MOD * (j & 1 ? -1 : 1);

            pre[j] += pow.ret(sum, j, MOD);
            now = (now % MOD + MOD) % MOD; pre[j] %= MOD;
        }

        result += now; result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}