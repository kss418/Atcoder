#include <bits/stdc++.h>
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
class _prop { // 구간 예외 처리하기
public:
    class node{
    public:
        ll v, len;
        node() : node(0, 0){}
        node(ll v, ll len) : v(v), len(len){}
        
        node& operator += (node ot){ // add
            v += ot.v; v %= MOD;
            return *this;
        }

        operator T(){ // node -> query
            return v;
        }
    };

    class lazy_type{
    public:
        ll v;
        lazy_type() : lazy_type(0){}
        lazy_type(ll v) : v(v){}

        lazy_type& operator += (lazy_type ot){ // add
            v += ot.v; v %= MOD;
            return *this;
        }
    };

    vector<node> seg, tmp; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        return { (l.v + r.v) % MOD, l.len + r.len };
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return !lazy.v;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s += p;
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        seg.v += (seg.len * lazy.v) % MOD;
        seg.v %= MOD;
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy = 0;
    }

    _prop() {}
    _prop(ll n) {
        this->n = n; seg.resize(4 * n + 1, node()); 
        lazy.resize(4 * n + 1, lazy_type());
        tmp.resize(4 * n + 1, node()); 
    }

    void propagate(ll l, ll r, ll node) {
        if (empty(lazy[node])) return;
        if (l != r) {
            prop(lazy[node * 2], lazy[node]);
            prop(lazy[node * 2 + 1], lazy[node]);
        }
        cal(lazy[node], seg[node]);
        erase(lazy[node]);
    }

    void add(ll st, ll en, lazy_type val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, lazy_type val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] += val; propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return _prop::node();
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }
    
    void set(ll idx, node val){
        tmp[idx] = val;
    }

    void init(){ init(0, n); }
    void init(ll l, ll r, ll node = 1){
        if(l == r){
            seg[node] = tmp[l];
            return;
        }

        ll mid = (l + r) >> 1ll;
        init(l, mid, node * 2);
        init(mid + 1, r, node * 2 + 1);
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }
};

ll org[MAX];
class _uf { 
public:
    ll n, m; vector <ll> p, si;
    vector <vector<ll>> arr;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
        arr.resize(n + 1);

        for(int i = 1;i <= n;i++){
            arr[i].push_back(i);
            org[i] = 1;
        }
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];

        ll sz = arr[a].size();
        for(auto& i : arr[b]){
            arr[a].push_back(i);
            org[i] += sz;
        }
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

class _ufset { 
public:
    ll n; vector <ll> p, si, l, r;
    
    _ufset(){}
    _ufset(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
        l.resize(n + 1); r.resize(n + 1);
        iota(all(l), 0); iota(all(r), 0);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
        l[a] = min(l[a], l[b]);
        r[a] = max(r[a], r[b]);
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll prv(ll num){ return find(l[find(num)] - 1); }
    ll nxt(ll num){ return find(r[find(num)] + 1); }
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
}; _inv inv;

pll arr[MAX];

void run(){
    cin >> n; _uf uf(n); _ufset ufset(n); _prop seg(n);
    for(int i = 1;i <= n;i++) seg.set(i, {0, 1}); seg.init();

    for(int i = 1;i < n;i++){
        cin >> arr[i].x >> arr[i].y;
        uf.merge(arr[i].x, arr[i].y);
    }

    for(int i = 1;i < n;i++){
        auto& [a, b] = arr[i];
        ll oa = org[a], ob = org[b];
        ll sa = ufset.size(oa), sb = ufset.size(ob), sz = sa + sb;

        ll la = ufset.l[ufset.find(oa)], ra = ufset.r[ufset.find(oa)];
        ll lb = ufset.l[ufset.find(ob)], rb = ufset.r[ufset.find(ob)];

        seg.add(la, ra, inv.ret(sa, sz, MOD));
        seg.add(lb, rb, inv.ret(sb, sz, MOD));

        ufset.merge(oa, ob);
    }

    for(int i = 1;i <= n;i++){
        ll now = org[i];
        cout << seg.query(now, now) << " ";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}