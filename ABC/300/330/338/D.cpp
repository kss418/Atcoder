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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class _prop { 
public:
    vector<ll> seg, lazy, arr; ll n;

    _prop(ll n) {
        this->n = n; arr.resize(n + 1);
        seg.resize(4 * n + 1); lazy.resize(4 * n + 1);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    void propagate(ll l, ll r, ll node) {
        if (!lazy[node]) return;
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        seg[node] += lazy[node] * (r - l + 1);
        lazy[node] = 0;
    }

    void add(ll st, ll en, ll val) { add(st, en, val, 1, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node] += val; propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
    }

    ll query(ll st, ll en) { return query(st, en, 1, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return INF;
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2);
        ret = min(query(st, en, mid + 1, r, node * 2 + 1), ret);

        return ret;
    }
};

void run(){
    cin >> n >> m; _prop seg(n);
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 1;i < m;i++){
        ll s = a[i], e = a[i + 1];
        if(s > e) swap(s, e);

        if(e - s < s + n - e) seg.add(s, e - 1, s + n - e - e + s);
        else if(s + n - e < e - s){
            seg.add(e, n, e - s - s - n + e); 
            if(s != 1) seg.add(1, s - 1, e - s - s - n + e);
        }
    }

    ll result = 0, mn = 1;
    for(int i = 1;i <= n;i++){
        ll now = seg.query(i, i);
        if(now < seg.query(mn, mn)) mn = i;
    }

    for(int i = 1;i < m;i++){
        ll s = a[i], e = a[i + 1];
        if(s > e) swap(s, e);

        if(e - s < s + n - e){
            if(mn >= s && mn < e) result += s + n - e;
            else result += e - s;
        }
        else if(s + n - e < e - s){
            if(mn >= e || mn < s) result += e - s;
            else result += s + n - e;
        }
        else result += e - s;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
