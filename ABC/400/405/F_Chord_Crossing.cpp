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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result[201010];
class query{
public: 
    ll now, nxt, op, idx;
    bool operator < (const query& ot) const{
        return now < ot.now;
    }
};
vector <query> q;

class node{
public:
    ll s, e, v;
    bool operator < (const node& ot) const{
        return s < ot.s;
    }
};
vector <node> arr;

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

void run(){
    cin >> n >> m; _seg seg1(4 * n), seg2(4 * n);
    while(m--){
        ll s, e; cin >> s >> e;

        arr.push_back({s, e, 1});
        arr.push_back({e, s, -1});
    }
    sort(all(arr));

    cin >> k;
    for(int i = 1;i <= k;i++){
        ll s, e; cin >> s >> e;

        q.push_back({s, e, 1, i});
        q.push_back({e, s, -1, i});
    }
    sort(all(q));

    ll cur = 0;
    for(auto& [now, nxt, op, idx] : q){
        while(cur < arr.size() && arr[cur].s < now){
            if(arr[cur].v == 1){
                seg1.add(arr[cur].s, 1);
                seg2.add(arr[cur].e, 1);
            }
            else{
                seg1.add(arr[cur].e, -1);
                seg2.add(arr[cur].s, -1);
            }
            cur++;
        }

        if(op == 1){
            result[idx] += seg1.query(0, now); 
            result[idx] -= seg2.query(nxt, 4 * n); 
        }
        else{
            result[idx] += seg2.query(now, 4 * n); 
            result[idx] -= seg1.query(0, nxt);
        }
    }   

    for(int i = 1;i <= k;i++) cout << result[i] << "\n";
} 

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

