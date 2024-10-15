#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX];

class _mxseg {
public:
    ll n; vector <ll> arr, seg;
    _mxseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = max(init(l, mid, node * 2), init(mid + 1, r, node * 2 + 1));
        return seg[node];
    }

    ll query(ll st, ll en) { return query(st, en, 1, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return -INF;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return max(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    ll update(ll idx, ll val) { return update(idx, val, 1, n); }
    ll update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = max(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));
        return seg[node];
    }
};

vector <tll> num;
vector <char> tr;

int main() {
    fastio;

    cin >> n >> m >> k;
    while(k--){
        ll x, y; cin >> y >> x;
        num.push_back({y, x, 0});
    }
    num.push_back({1, 1, 0});

    sort(all(num)); _mxseg seg(m);
    for(auto& i : num){
        auto& [y, x, c] = i;
        if(x == 1 && y == 1) continue;
        ll cnt = seg.query(1, x) + 1;
        seg.update(x, cnt); c = cnt;
    }

    ll result = seg.query(1, m);
    reverse(all(num)); ll cx = m, cy = n;
    cout << result << "\n";
    
    for(auto& i : num){
        auto& [y, x, c] = i;
        if(c != result) continue;
        for(int j = cx;j > x;j--) tr.push_back('R');
        for(int j = cy;j > y;j--) tr.push_back('D');
        
        cx = x; cy = y; result--;
    }

    reverse(all(tr));
    for(auto& i : tr) cout << i;


    return 0;
}
