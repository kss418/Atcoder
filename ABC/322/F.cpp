#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
set <pll> arr;

template <typename T = ll> // query type
class _prop { // 구간 예외 처리하기
public:
    class node{
    public:
        ll mx[2], l[2], r[2], len;
        node() : node(0, 0, 0, 0, 0, 0, 0){}
        node(ll mx0, ll mx1, ll l0, ll l1, ll r0, ll r1, ll len){
            mx[0] = mx0; mx[1] = mx1;
            l[0] = l0; l[1] = l1;
            r[0] = r0; r[1] = r1; this->len = len;
        }
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return mx[1];
        }
    };

    class lazy_type{
    public:
        ll v;
        lazy_type() : lazy_type(0){}
        lazy_type(ll v) : v(v){}
    };

    vector<node> seg; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        node ret;
        for(int i = 0;i < 2;i++){
            ret.l[i] = l.l[i] + (l.l[i] == l.len ? r.l[i] : 0);
            ret.r[i] = r.r[i] + (r.r[i] == r.len ? l.r[i] : 0);
            ret.mx[i] = max({l.mx[i], r.mx[i], l.r[i] + r.l[i]});
        }
        ret.len = l.len + r.len;
        return ret;
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return !lazy.v;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s.v ^= p.v;
    }

    node flip(node seg){
        swap(seg.mx[0], seg.mx[1]);
        swap(seg.l[0], seg.l[1]);
        swap(seg.r[0], seg.r[1]);
        return seg;
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        if(lazy.v == 1) seg = flip(seg);
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy = 0;
    }

    _prop() {}
    _prop(ll n) {
        this->n = n; 
        seg.resize(4 * n + 1, node()); lazy.resize(4 * n + 1, lazy_type());
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

    void set(ll st, ll en, ll val) { set(st, en, val, 0, n); }
    void set(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            for(int i = 0;i < 2;i++){
                seg[node].mx[i] = seg[node].r[i] = seg[node].l[i] = (val == i);
            }
            seg[node].len = 1;
            return;
        }

        ll mid = (l + r) >> 1;
        set(st, en, val, l, mid, node * 2);
        set(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void add(ll st, ll en, ll val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].v ^= val; propagate(l, r, node);
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
};


void run(){
    cin >> n >> m >> s; _prop seg(n);
    for(int i = 0;i < n;i++) seg.set(i, i, s[i] - '0');

    while(m--){
        ll c, l, r; cin >> c >> l >> r;
        if(c == 1) seg.add(l - 1, r - 1, 1);
        else cout << seg.query(l - 1, r - 1) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

