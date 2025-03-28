#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll t[MAX], p[MAX];
ll dp[MAX];

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

int main() {
    fastio;

    cin >> n >> m >> k;
    _mxseg nxt(n + 1), pre(n + 1);
        
    fill(dp, dp + k + 1, -INF);
    for(int i = 1;i <= n;i++){
        pre.con(i, -INF); nxt.con(i, -INF);
    }
    pre.init(); nxt.init();
    dp[0] = 0;

    pre.update(1, m); nxt.update(1, -m);
    for(int i = 1;i <= k;i++) {
        cin >> t[i] >> p[i];
        dp[i] = max(dp[i], pre.query(1, t[i]) + p[i] - m * t[i]);
        dp[i] = max(dp[i], nxt.query(t[i], n) + p[i] + m * t[i]);
        pre.update(t[i], dp[i] + m * t[i]);
        nxt.update(t[i], dp[i] - m * t[i]);
    }

    ll result = -INF;
    for(int i = 0;i <= k;i++) result = max(dp[i], result);

    cout << result;
    
    
    return 0;
}
