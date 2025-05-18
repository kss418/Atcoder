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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v;
        node() : node(0){}
        node(ll v) : v(v) {}
        
        node operator += (node ot){ // add
            return v += ot.v;
        }

        operator T(){ // update -> query
            return v;
        }
    };
    vector <node> seg;

    _seg(){}
    _seg(ll n) { this->n = n; seg.resize(4 * n + 1, node()); }

    node merge(node l, node r){
        return{
            l.v + r.v
        };
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
            seg[node] = val;
            return seg[node];
        }
        ll mid = (l + r) >> 1;
        return seg[node] = merge(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));;
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

    void clear(){ seg.clear(); seg.assign(4 * n + 1, node()); }
};

ll cnt, in[MAX], out[MAX], d[MAX];
void init(ll cur, ll dep = 0, ll pre = -1){
    in[cur] = ++cnt;
    d[cur] = dep;
    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue;
        init(nxt, dep + 1, cur);
    }
    out[cur] = cnt;
}
pll l[MAX];

void run(){
    cin >> n; _seg seg(n);
    for(int i = 1;i < n;i++){
        cin >> l[i].x >> l[i].y;
        adj[l[i].y].push_back(l[i].x);
        adj[l[i].x].push_back(l[i].y);
    }
    init(1);
    for(int i = 1;i <= n;i++) seg.add(in[i], 1);

    cin >> m;
    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll idx, v; cin >> idx >> v;
            seg.add(in[idx], v);
        }
        else{
            ll idx; cin >> idx;
            auto[s, e] = l[idx];
            ll mx = (d[s] < d[e] ? e : s);

            ll all = seg.query(in[1], out[1]);
            ll a = seg.query(in[mx], out[mx]);
            ll b = all - a;
            cout << abs(a - b) << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

