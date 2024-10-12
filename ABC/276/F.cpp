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
ll a[MAX];

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

class _sseg {
public:
    ll n; vector <ll> arr, seg;
    _sseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    ll query(ll st, ll en) { return query(st, en, 1, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return 0;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }

    void add(ll idx, ll val) { add(idx, val, 1, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        add(idx, val, l, mid, node * 2);
        add(idx, val, mid + 1, r, node * 2 + 1);
    }

    ll update(ll idx, ll val) { return update(idx, val, 1, n); }
    ll update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = update(idx, val, l, mid, node * 2);
        seg[node] += update(idx, val, mid + 1, r, node * 2 + 1);
        return seg[node];
    }
};

int main() {
    fastio;

    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll sum = 0, result = 0; _sseg seg(MAX), cnt(MAX);
    _pow pow; _inv inv;
    for(ll i = 1;i <= n;i++){
        sum += a[i]; sum %= MOD;
        sum += cnt.query(1, a[i]) * a[i] * 2; sum %= MOD;
        sum += seg.query(a[i] + 1, MAX) * 2; sum %= MOD;

        cout << inv.ret(sum, i * i, MOD)<< "\n";
        seg.add(a[i], a[i]); cnt.add(a[i], 1);
    }

    return 0;
}
