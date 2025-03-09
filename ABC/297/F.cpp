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

void run(){
    cin >> n >> m >> k;
    _inv inv; _comb comb(MAX * MAX, MOD);
    if(k == 1){ cout << 1; return; }
    ll all = comb.ret(n * m, k), sum = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ll now = 0;
            now += comb.ret((i - 1) * m, k);
            now += comb.ret((n - i) * m, k);
            now += comb.ret((j - 1) * n, k);
            now += comb.ret((m - j) * n, k);
            now %= MOD;
            
            now -= comb.ret((i - 1) * (j - 1), k);
            now -= comb.ret((n - i) * (j - 1), k);
            now -= comb.ret((i - 1) * (m - j), k);
            now -= comb.ret((n - i) * (m - j), k);

            sum += (all - now + MOD) % MOD; sum %= MOD;
        }   
    }

    cout << inv.ret(sum, all, MOD);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
