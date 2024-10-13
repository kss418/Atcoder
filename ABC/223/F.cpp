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

class _prop {
public:
    vector<ll> seg, lazy, arr; ll n;

    _prop(ll n) {
        this->n = n; arr.resize(n + 1);
        seg.resize(4 * n + 1); lazy.resize(4 * n + 1);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(0, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = min(init(l, mid, node * 2), init(mid + 1, r, node * 2 + 1));
        return seg[node];
    }

    void propagate(ll l, ll r, ll node) {
        if (!lazy[node]) return;
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        seg[node] += lazy[node];
        lazy[node] = 0;
    }

    void add(ll st, ll en, ll val) { add(st, en, val, 0, n); }
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

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return INF;
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2);
        ret = min(ret, query(st, en, mid + 1, r, node * 2 + 1));

        return ret;
    }
};

int main() {
    fastio;

    cin >> n >> m >> s;
    _prop prop(n); ll cnt = 0; prop.con(0, 0);
    for(int i = 1;i <= n;i++) {
        if(s[i - 1] == '(') cnt++; else cnt--;
        prop.con(i, cnt);
    }
    prop.init();

    while(m--){
        ll num, l, r; cin >> num >> l >> r;
        if(num == 1){
            if(s[l - 1] == '(') prop.add(l, n, -1);
            else prop.add(l, n, 1);
            if(s[r - 1] == '(') prop.add(r, n, -1);
            else prop.add(r, n, 1);

            swap(s[l - 1], s[r - 1]);

            if(s[l - 1] == '(') prop.add(l, n, 1);
            else prop.add(l, n, -1);
            if(s[r - 1] == '(') prop.add(r, n, 1);
            else prop.add(r, n, -1);
        }
        else{
            ll mid = prop.query(l, r);
            ll la = prop.query(r, r);
            ll pre = prop.query(l - 1, l - 1);
            mid -= pre; la -= pre;

            if(mid < 0 || la) cout << "No\n";
            else cout << "Yes\n";
        }
    }


    return 0;
}
