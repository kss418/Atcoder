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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
class query{
public:
    ll t, x1, x2, num;
    bool operator < (const query& ot){
        if(t == ot.t) return num < ot.num;
        return t > ot.t;
    }
};
vector <query> q;

class _prop { 
public:
    vector<ll> seg, lazy; ll n;

    _prop(ll n) {
        this->n = n; 
        seg.resize(4 * n + 1, 0ll); lazy.resize(4 * n + 1, 0ll);
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

        seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    }

    ll query(ll st, ll en) { return query(st, en, 0, n); }
    ll query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return 0;
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        ll ret = query(st, en, l, mid, node * 2);
        ret = max(ret, query(st, en, mid + 1, r, node * 2 + 1));

        return ret;
    }
};

void run(){
    cin >> n >> m >> k; _prop seg(MAX);
    for(int i = 1;i <= n;i++) {
        ll t, x; cin >> t >> x;
        ll sx = max(x - k + 1, 1ll), ex = x;
        ll nt = t + m;

        q.push_back({t - 1, sx, ex, -1});
        q.push_back({nt - 1, sx, ex, 1});
    }
    sort(all(q));

    ll result = 0;
    for(auto& i : q){
        auto[t, x1, x2, num] = i;
        seg.add(x1, x2, num);
        result = max(result, seg.query(1, MAX));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
