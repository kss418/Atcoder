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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        char l, r;
        ll lv, rv, sz, ret;
        node() : node(0, 0, 0, 0, 0, 0){}
        node(char l, char r, ll lv, ll rv, ll sz, ll ret) : 
            l(l), r(r), lv(lv), rv(rv), sz(sz), ret(ret) {}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return ret;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    node merge(node l, node r){
        node ret;
        ret.l = l.l; ret.r = r.r;
        ret.sz = l.sz + r.sz;
        ret.lv = l.lv; ret.rv = r.rv;

        if(l.sz == l.lv && l.r == r.l){
            ret.lv = l.lv + r.lv;
        }
        if(r.sz == r.rv && l.r == r.l){
            ret.rv = l.rv + r.rv;
        }

        if(l.r == r.l){
            ret.ret = l.rv + r.lv;
        }
        ret.ret = max({ret.ret, l.ret, r.ret});

        return ret;
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    node update(ll idx, ll val) { return update(idx, val, 0, n); }
    node update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) {
            seg[node] = {val, val, 1, 1, 1, 1};
            return seg[node];
        }
        ll mid = (l + r) >> 1;
        return seg[node] = merge(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));;
    }

    void clear(){ seg.clear(); seg.assign(4 * n + 1, node()); }
};

void run(){
    cin >> n >> m >> s; _seg seg(n);
    for(int i = 1;i <= n;i++) seg.update(i, s[i - 1]);

    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll idx; char c; cin >> idx >> c;
            seg.update(idx, c);
        }
        else{
            ll l, r; cin >> l >> r;
            cout << seg.query(l, r) << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

