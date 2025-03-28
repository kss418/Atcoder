#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], arr[MAX], num[MAX];
stack <pll> st;

template <typename T = ll> // query type
class _seg { // 구간 예외 처리하기
public:
    ll n;
    class node{
    public:
        ll v;
        node() : node(0){}
        node(ll v) {
            this->v = v;
        }

        node operator + (node ot){ // update
            ll now = v + ot.v;
            return node(now);
        }

        node operator += (T ot){ // add
            v += ot;
            return node(v);
        }

        operator T(){ // update -> query
            return v;
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
vector <tll> query;
deque <pll> q;
ll result[MAX];

int main() {
    fastio;

    cin >> n >> m; _seg seg(MAX);
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++){
        ll l, r; cin >> l >> r;
        query.push_back({l, r, i});
    }

    sort(all(query), [](tll a, tll b){ return get<0>(a) > get<0>(b); });

    ll idx = n;
    for(auto& i : query){
        auto[l, r, now] = i;
        while(idx > l){
            while(!q.empty() && q.back().x < a[idx]) {
                seg.update(q.back().y, 0); q.pop_back(); 
            }
            q.push_back({a[idx], idx}); 
            seg.update(q.back().y, 1); idx--;
        }

        result[now] = seg.query(r + 1, n);
    }

    for(int i = 1;i <= m;i++) cout << result[i] << "\n";


    return 0;
}

