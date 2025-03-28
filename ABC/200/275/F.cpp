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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 3010;
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX], dp[MAX][MAX];

class _mnseg {
public:
    ll n; vector <ll> arr, seg;
    _mnseg(){}
    _mnseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1, INF);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = min(init(l, mid, node * 2), init(mid + 1, r, node * 2 + 1));
        return seg[node];
    }

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return INF;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return min(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }

    ll update(ll idx, ll val) { return update(idx, val, 0, n); }
    ll update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = min(update(idx, val, l, mid, node * 2), update(idx, val, mid + 1, r, node * 2 + 1));
        return seg[node];
    }
};
_mnseg seg[MAX];


ll solve(ll cur, ll num){
    if(cur < 0 || num < 0 || num > m) return INF;
    ll& ret = dp[cur][num];
    if(ret != -1) return ret;
    if(!cur) return INF;  
    ret = INF;
    
    ret = min(solve(cur - 1, num - (sum[cur] - sum[cur - 1])), ret);
    solve(cur - 1, num);
    ret = min(seg[num].query(0, cur - 1) + 1, ret);
    seg[num].update(cur, ret);

    return ret;
}

int main() {
    fastio;

    cin >> n >> m; 
    for (int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
    for(int i = 0;i <= m;i++) seg[i] = {n};
    memset(dp, -1, sizeof(dp));

    for(int i = 0;i <= n;i++){
        if(sum[i] > m) break;
        dp[i][sum[i]] = 0; seg[sum[i]].update(i, 0);
    }

    for(int i = 1;i <= m;i++) {
        ll ret = solve(n, i);   
        if(ret >= INF) cout << -1 << "\n";
        else cout << ret << "\n";
    }

    
    return 0;
}
