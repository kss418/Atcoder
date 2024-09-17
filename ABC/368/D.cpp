#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
deque <pll> arr;
ll use[MAX];

class _lca {
public:
    ll n; vector <ll> d;
    vector <vector<ll>> p, adj;
    _lca(ll n) { //n 개수
        this->n = n;
        p.resize(n + 1, vector<ll>(log2(n + 1) + 1, -1));
        d.resize(n + 1); adj.resize(n + 1);
        fill(d.begin(), d.end(), -1);
    }

    void add(ll a, ll b) { // 양방향
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void mktree(ll cur) {
        for (auto& nxt : adj[cur]) {
            if (d[nxt] != -1) continue;
            p[nxt][0] = cur;
            d[nxt] = d[cur] + 1;
            mktree(nxt);
        }
    }

    void init(ll root) {
        d[root] = 0;
        mktree(root);

        for (int i = 1; i <= log2(n); i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j][i - 1] == -1) continue;
                p[j][i] = p[p[j][i - 1]][i - 1];
            }
        }
    }

    ll ret(ll a, ll b) {
        if (d[a] < d[b]) swap(a, b);

        ll diff = d[a] - d[b];
        for (int i = log2(diff); i >= 0; i--) {
            if (diff & (1ll << i)) a = p[a][i];
        }
        if (a == b) return a;

        for (int i = log2(n); i >= 0; i--) {
            if (a == b) break;
            if (p[a][i] == -1) continue;
            if (p[a][i] == p[b][i]) continue;

            a = p[a][i]; b = p[b][i];
        }

        return p[a][0];
    }
};



int main()
{
    fastio;
    cin >> n >> m;
    _lca lca(n);
    for (int i = 1; i < n; i++) {
        ll st, en;
        cin >> st >> en;
        lca.add(st, en);
    }
    lca.init(1);

    while (m--) {
        ll cur; cin >> cur;
        arr.push_back({ lca.d[cur], cur });
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    ll top = arr.back().second;
    for (auto& i : arr) top = lca.ret(top, i.second);

    ll result = 0;
    while (!arr.empty()) {
        auto [cd, st] = arr.front(); arr.pop_front();
        ll cur = st;
        while (1) {
            if (cur == -1) break;
            if (cur == lca.p[lca.ret(top, st)][0]) break;
            if (use[cur]) break;

            use[cur] = 1; result++;
            cur = lca.p[cur][0];
        }
    }

    cout << result;


    return 0;
}