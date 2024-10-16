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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], st[MAX], pc[MAX], sc[MAX];

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
        if (en < l || st > r) return 0;
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
map <ll, ll> num;
vector <ll> result;

int main() {
    fastio;

    cin >> t; 
    while(t--){
        cin >> n; _mxseg pre(n), suf(n); num.clear();
        for (int i = 1;i <= n;i++) {
            cin >> a[i]; st[i] = a[i];
        }

        sort(st + 1, st + n + 1); ll seq = 1, mx = 0;
        for (int i = 1;i <= n;i++) {
            if(num.find(st[i]) == num.end()) num[st[i]] = seq++;
        }
        for(int i = 1;i <= n;i++) a[i] = num[a[i]];


        for(int i = 1;i <= n;i++){
            ll cur = a[i];
            ll q = pre.query(1, cur - 1);
            pre.update(cur, q + 1); pc[i] = q;
            mx = max(mx, q + 1);
        }

        for(int i = n;i >= 1;i--){
            ll cur = a[i];
            ll q = suf.query(cur + 1, n);
            suf.update(cur, q + 1); sc[i] = q;     
        }  

        for(int i = 1;i <= n;i++){
            if(pc[i] + sc[i] == mx - 1) result.push_back(i);
        }

        cout << result.size() << "\n";
        for(auto& i : result) cout << i << " ";
        cout << "\n"; result.clear();
    }

    
    
    return 0;
}
