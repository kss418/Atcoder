#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
pll num[MAX];
vector<ll> arr;
map <ll, ll> tra;

class _sseg {
public:
    ll n; vector <ll> arr, seg;
    _sseg(ll n) {
        this->n = n;
        arr.resize(n + 1); seg.resize(4 * n + 1);
    }

    void con(ll idx, ll val) { arr[idx] = val; }

    void init() { init(1, n); }
    ll init(ll l, ll r, ll node = 1) {
        if (l == r) return seg[node] = arr[l];
        ll mid = (l + r) >> 1;
        seg[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);
        return seg[node];
    }

    ll query(ll st, ll en) { return query(st, en, 1, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        if (en < l || st > r) return 0;
        if (st <= l && en >= r) return seg[node];
        ll mid = (l + r) >> 1;
        return query(st, en, l, mid, node * 2) + query(st, en, mid + 1, r, node * 2 + 1);
    }

    void add(ll idx, ll val) { add(idx, val, 1, n); }
    void add(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return;
        seg[node] += val;
        if (l == r) return;
        ll mid = (l + r) >> 1;
        add(l, mid, idx, val, node * 2);
        add(mid + 1, r, idx, val, node * 2 + 1);
    }

    ll update(ll idx, ll val) { return update(idx, val, 1, n); }
    ll update(ll idx, ll val, ll l, ll r, ll node = 1) {
        if (idx < l || idx > r) return seg[node];
        if (l == r) return seg[node] = val;
        ll mid = (l + r) >> 1;

        seg[node] = update(idx, val, l, mid, node * 2);
        seg[node] += update(idx, val, mid + 1, r, node * 2 + 1);
        return seg[node];
    }
};

int main() {
    fastio;

    cin >> n; _sseg seg(n);
    for (int i = 1; i <= n; i++) {
        cin >> num[i].first; arr.push_back(num[i].first);
    }
    for (int i = 1; i <= n; i++) cin >> num[i].second;
    sort(num + 1, num + n + 1); sort(arr.begin(), arr.end());
    ll cnt = 1;

    for (int i = 1; i <= n; i++) {
        if (!tra.count(num[i].first)) tra[num[i].first] = cnt++;
        seg.con(tra[num[i].first], num[i].second);
    }
    seg.init();

    cin >> m;
    while (m--) {
        ll st, en;
        cin >> st >> en;
        auto sb = lower_bound(arr.begin(), arr.end(), st);
        if (sb == arr.end()) {
            cout << 0 << "\n"; continue;
        }
        st = tra[*sb];

        auto eb = upper_bound(arr.begin(), arr.end(), en); eb--;
        en = tra[*eb];
        if (en < st) cout << 0 << '\n';
        else cout << seg.query(st, en) << "\n";
    }



    return 0;
}
