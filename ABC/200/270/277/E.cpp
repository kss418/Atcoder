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
ll n, m, k, t;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
bool s[MAX];

template <typename T = ll>
class _dij {
public:
    using ptl = pair <T, ll>;
    ll n; vector <vector<T>> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <tll, vector<tll>, greater<tll>> pq;

    _dij(ll n) {
        this->n = n;
        d.resize(n + 1, vector<ll>(2,INF)); pre.resize(n + 1, -1);
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
        d[st][1] = fi;
        pq.push({ d[st][1], st, 1 });

        while (!pq.empty()) {
            auto [cd, cur, cc] = pq.top(); pq.pop();
            if (cd > d[cur][cc]) continue;

            for (auto& nn : adj[cur]) {
                auto [nc, nxt] = nn;
                if(nc != cc && !s[cur]) continue;
                if (d[nxt][nc] <= 1 + cd) continue;

                d[nxt][nc] = 1 + cd;
                pre[nxt] = cur;
                pq.push({ d[nxt][nc], nxt, nc });
            }
        }
    }

};

int main() {
    fastio;

    cin >> n >> m >> k; _dij dij(n);
    while(m--){
        ll u, v, a; cin >> u >> v >> a;
        dij.add(u, v, a);
    }
    for(int i = 1;i <= k;i++) cin >> t, s[t] = 1;

    dij.init(1, 0);
    ll result = min(dij.d[n][0], dij.d[n][1]);
    if(result >= INF) cout << -1;
    else cout << result;


    return 0;
}
