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
ll md[4] = { MOD, 1000000007, 1000000009, 1000000021 };
ll base[4] = {26, 31, 39, 41};
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

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n, mod;
    class node{
    public:
        ll v, mod;
        node(ll mod) : node(0, mod){}
        node(ll v, ll mod) {
            this-> v = (v % mod);
            this-> mod = mod;
        }

        node operator + (node ot){ // update
            ll now = (v + ot.v) % mod;
            return node(now, mod);
        }

        node operator += (T ot){ // add
            v += ot; v %= mod;
            return node(v, mod);
        }

        operator T(){ // update -> query
            return v;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n, ll md) {
        this->n = n; mod = md;
        seg.resize(4 * n + 1, node(mod));
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node(mod);
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }

    node update(ll idx, ll val) { return update(idx, val, 0, n); }
    node update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = _seg::node(val, mod);
        ll mid = (l + r) >> 1;

        seg[node] = update(idx, val, l, mid, node * 2) + update(idx, val, mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    void add(ll idx, ll val) { add(idx, val, 0, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;

        add(idx, val, l, mid, node * 2);
        add(idx, val, mid + 1, r, node * 2 + 1);
    }
};


void run(){
    cin >> n >> m >> s; _seg <ll> seg[4][2]; _pow pow; _inv inv;
    for(int i = 0;i < 4;i++) {
        for(int j = 0;j < 2;j++) seg[i][j] = {n, md[i]};
    }
    
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < 4;j++){
            seg[j][0].update(i, (s[i] - 'a' + 1) * pow.ret(base[j], i, md[j]));
            seg[j][1].update(i, (s[i] - 'a' + 1) * pow.ret(base[j], n - i - 1, md[j]));
        }
    }
    
    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll idx; char c; cin >> idx >> c; idx--;
            for(int i = 0;i < 4;i++) {
                seg[i][0].update(idx, (c - 'a' + 1) * pow.ret(base[i], idx, md[i]));
                seg[i][1].update(idx, (c - 'a' + 1) * pow.ret(base[i], n - idx - 1, md[i]));
            }
        }
        else{
            ll l, r; cin >> l >> r;
            ll now = 1; l--; r--;
            for(int i = 0;i < 4;i++){
                ll pre = seg[i][0].query(l, r), suf = seg[i][1].query(l, r);
                pre *= inv.ret(1, pow.ret(base[i], max(l, 0ll), md[i]), md[i]);
                suf *= inv.ret(1, pow.ret(base[i], max(n - r - 1, 0ll), md[i]), md[i]);
                pre %= md[i]; suf %= md[i];
                if(pre != suf){ now = 0; break; }
            }
            
            cout << (now ? "Yes" : "No") << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

