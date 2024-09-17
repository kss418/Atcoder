#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;

template <typename T = ll>
class _dij {
public:
    using ptl = pair <T, ll>;
    ll n; vector <T> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

    _dij(ll n) {
        this->n = n;
        d.resize(n + 1, INF); pre.resize(n + 1, -1);
        adj.resize(n + 1);
    }

    void add(ll st, ll en, ll c = 1) { // 양방향
        adj[st].push_back({ c,en });
        adj[en].push_back({ c,st });
    }

    void addsol(ll st, ll en, ll c = 1) { // 단방향
        adj[st].push_back({ c,en });
    }

    void init(ll st, T fi = 0) {
        d[st] = fi;
        pq.push({ d[st], st });

        while (!pq.empty()) {
            auto [cd, cur] = pq.top(); pq.pop();
            if (cd > d[cur]) continue;

            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (d[nxt] <= nd + cd) continue;

                d[nxt] = nd + cd;
                pre[nxt] = cur;
                pq.push({ d[nxt], nxt });
            }
        }
    }

    T ret(ll n) {
        return d[n];
    }
};

int main() {
    fastio;

    cin >> n >> m;
    _dij dij(2 * n);
    for (int i = 1; i <= n; i++) {
        cin >> k;
        dij.addsol(i, i + n, k);
    }

    while (m--) {
        ll st, en, c;
        cin >> st >> en >> c;
        dij.addsol(st + n, en, c);
        dij.addsol(en + n, st, c);
    }
    dij.init(1);
    
    for (int i = 2; i <= n; i++) cout << dij.ret(i + n) << " ";


    return 0;
}
