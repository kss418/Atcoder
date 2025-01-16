#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
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
} inv;

class _prop {
public:
    vector<ll> seg, arr; ll n;
    vector<pll> lazy;

    _prop(ll n) {
        this->n = n; arr.resize(n + 1);
        seg.resize(4 * n + 1); lazy.resize(4 * n + 1, { 1,0 });
    }

    void propagate(ll l, ll r, ll node) {
        if (lazy[node] == pll(1,0)) return;
        if (l != r) {
            lazy[node * 2].first *= lazy[node].first;
            lazy[node * 2].second *= lazy[node].first;
            lazy[node * 2].second += lazy[node].second;
            lazy[node * 2].first %= MOD;
            lazy[node * 2].second %= MOD;
            lazy[node * 2 + 1].first *= lazy[node].first;
            lazy[node * 2 + 1].second *= lazy[node].first;
            lazy[node * 2 + 1].second += lazy[node].second;
            lazy[node * 2 + 1].first %= MOD;
            lazy[node * 2 + 1].second %= MOD;
        }
        seg[node] *= lazy[node].first;
        seg[node] %= MOD;
        seg[node] += lazy[node].second * (r - l + 1);
        seg[node] %= MOD;
        lazy[node] = { 1,0 };
    }

    void set(ll st, ll en, ll val) { set(st, en, val, 1, n); }
    void set(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].first = 0;
            lazy[node].second = val;
            propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        set(st, en, val, l, mid, node * 2);
        set(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
        seg[node] %= MOD;
    }

    void mul(ll st, ll en, ll val) { mul(st, en, val, 1, n); }
    void mul(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].first *= val;
            lazy[node].first %= MOD;
            lazy[node].second *= val;
            lazy[node].second %= MOD;
            propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        mul(st, en, val, l, mid, node * 2);
        mul(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
        seg[node] %= MOD;
    }

    void add(ll st, ll en, ll val) { add(st, en, val, 1, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].second += val;
            lazy[node].second %= MOD;
            propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = seg[node * 2] + seg[node * 2 + 1];
        seg[node] %= MOD;
    }

    ll query(ll st, ll en) { return query(st, en, 1, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return 0;
        if (l >= st && r <= en) return seg[node] % MOD;

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2) % MOD;
        ret += query(st, en, mid + 1, r, node * 2 + 1) % MOD;

        return ret;
    }
};

void run(){
    cin >> n >> m; _prop seg(n);
    for(int i = 1;i <= n;i++) cin >> a[i], seg.set(i, i, a[i]);
    while(m--){
        ll l, r, x; cin >> l >> r >> x;
        seg.mul(l, r, inv.ret(r - l, r - l + 1, MOD));
        seg.add(l, r, inv.ret(x, r - l + 1, MOD));
    }

    for(int i = 1;i <= n;i++) cout << seg.query(i, i) << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

