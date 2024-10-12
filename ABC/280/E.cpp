#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

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
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
};

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

class _pow {
public:
	_pow() {}

	ll ret(ll a, ll p) {
		if (!p) return 1;
		if (p == 1) return a;

		ll cur = ret(a, p / 2);
		cur = cur * cur;
		if (p % 2 == 0) return cur;
		return cur * a;
	}

	ll ret(ll a, ll p, ll mod) {
		if (!p) return 1;
		if (p == 1) return a % mod;

		ll cur = ret(a, p / 2, mod);
		cur = cur * cur % mod;
		if (p % 2 == 0) return cur % mod;
		return (cur * a) % mod;
	}
};


int main() {
    fastio;

    cin >> n >> m; _comb comb(MAX);
    _pow pow; _inv inv;
    ll result = 0;
    for(int i = n;i >= 0;i--){
        ll two = n - i, one = n - 2 * two;
        ll cnt = one + two;
        if(two < 0 || one < 0) continue;

        ll tp = pow.ret(m, two, MOD);
        ll op = pow.ret(100 - m, one, MOD);
        ll div = inv.ret(1, pow.ret(100, i, MOD), MOD);
        ll c = comb.ret(cnt, two);

        ll cur = (cnt * tp) % MOD;
        cur *= (op * c) % MOD; cur %= MOD;
        cur *= div; cur %= MOD;
        result += cur; result %= MOD;
    }


    for(int i = n;i >= 0;i--){
        ll two = n - i + 1, one = n + 1 - 2 * two;
        ll cnt = one + two;
        if(two < 0 || one < 0) continue;

        ll tp = pow.ret(m, two, MOD);
        ll op = pow.ret(100 - m, one, MOD);
        ll div = inv.ret(1, pow.ret(100, i, MOD), MOD);
        ll c = comb.ret(cnt - 1, two - 1);
    
        ll cur = (cnt * tp) % MOD;
        cur *= (op * c) % MOD; cur %= MOD;
        cur *= div; cur %= MOD;
        result += cur; result %= MOD;
    }

    cout << result % MOD;


    return 0;
}
