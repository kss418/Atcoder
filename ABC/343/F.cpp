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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        pll v1, v2;
        node() : node({-INF, 0}, {-INF, 0}){}
        node(ll a) : node({a, 1}, {-INF, 0}){}
        node(ll a, ll b) : node({a, 1}, {b, 1}){}
        node(pll a, pll b){
            if(b.x > a.x) swap(a, b);
            this->v1 = a;
            this->v2 = b;
        }

        node operator + (node ot){ // update
            vector <pll> arr;
            arr.push_back(ot.v1);
            arr.push_back(ot.v2);
            arr.push_back(v1);
            arr.push_back(v2);
            sort(all(arr));
            reverse(all(arr));

            pll a = {arr[0].x, 0};
            pll b = {-INF, 0};
            for(auto &i : arr){
                if(a.x == i.x) continue;
                b.x = i.x; break;
            } 

            for(auto& i : arr){
                if(a.x == i.x) a.y += i.y;
                if(b.x == i.x) b.y += i.y;
            }
            
            node now = {a, b};
            return node(now);
        }

        node operator += (T ot){ // add
            v1 += ot;
            return node(v1);
        }

        operator T(){ // update -> query
            return v2.y;
        }
    };
    vector <node> seg, arr;

    _seg(){}
    _seg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return _seg::node();
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }

    node update(ll idx, ll val) { return update(idx, val, 0, n); }
    node update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
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



int main() {
    fastio;

    cin >> n >> m; _seg seg(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i], seg.update(i, a[i]);
    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll idx, v; cin >> idx >> v;
            seg.update(idx, v);
        }
        else{
            ll l, r; cin >> l >> r;
            cout << seg.query(l, r) << "\n";
        }
    }

     
    return 0;
}
