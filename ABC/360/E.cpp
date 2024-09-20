#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
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

    cin >> n >> m;
    _inv inv; _pow pow;

    ll ch = ((n * n) % MOD - (2 * (n - 1)) % MOD + MOD) % MOD;
    ll one = ch;
    for (int i = 2; i <= m; i++) {
        ll a = (one * ch) % MOD;
        ll b = ((pow.ret(n, 2 * (i - 1), MOD) - one + MOD) % MOD * 2) % MOD;

        one = (a + b) % MOD;
    }
    ll sum = one;
        
    one = 2;
    for (int i = 2; i <= m; i++) {
        ll a = (one * ch) % MOD;
        ll b = ((pow.ret(n, 2 * (i - 1), MOD) - one + MOD) % MOD * 2) % MOD;

        one = (a + b) % MOD;
    }

    ll mul = (n * (n + 1)) / 2 - 1;
    mul %= MOD;

    sum += ((one % MOD) * mul) % MOD;
    sum %= MOD;

    cout << inv.ret(sum, pow.ret(n, 2 * m, MOD), MOD);


    return 0;
}
