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
class query{
public:
    ll v, num, idx;
    bool operator < (const query& ot) const{
        return v < ot.v;
    }
};
vector <query> q;
ll a[MAX], result[MAX];
vector <ll> st;
vector <pll> arr;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v;
        node() : node(MINF){}
        node(ll v) : v(v) {}
        
        node operator += (node ot){ // add
            return node();
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
            max(l.v, r.v)
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

map <ll, ll> mp;
void comp(){
    sort(all(st)); ll cnt = 0;
    for(auto& i : st){
        if(!mp.count(i)) mp[i] = ++cnt;
    }
}

void run(){
    cin >> n >> m; _seg seg(2 * MAX);
    for(int i = 1;i < MAX;i++) seg.update(i, MINF);
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; st.push_back(a[i]);
    }
    
    for(int i = 1;i <= m;i++){
        ll v, num; cin >> v >> num;
        q.push_back({v, num, i});
        st.push_back(num);
    }
    sort(all(q));
    
    comp();
    for(int i = 1;i <= n;i++) a[i] = mp[a[i]];
    for(auto &i : q) i.num = mp[i.num];

    ll cur = 1; seg.update(0, 0);
    for(int i = 0;i < m;i++){
        auto[v, num, idx] = q[i];
        while(cur <= n && cur <= v){
            ll q = seg.query(0, a[cur] - 1);
            seg.update(a[cur], q + 1); cur++;
        }  
        
        result[idx] = seg.query(0, num);
    }

    for(int i = 1;i <= m;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

