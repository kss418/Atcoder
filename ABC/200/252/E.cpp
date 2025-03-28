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
ll p[MAX];

template <typename T = ll>
class _dij {
public:
    using ptl = pair <T, ll>;
    ll n; vector <T> d;
    vector <ll> pre;
    vector <vector<tll>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

    _dij(ll n) {
        this->n = n;
        d.resize(n + 1, INF); pre.resize(n + 1, -1);
        adj.resize(n + 1);
    }

    void add(ll st, ll en, ll c , ll num) { // 양방향
        adj[st].push_back({ c,en, num });
        adj[en].push_back({ c,st, num });
    }

    void addsol(ll st, ll en, ll c , ll num) { // 단방향
        adj[st].push_back({ c,en, num });
    }

    void init(ll st, T fi = 0) {
        d[st] = fi;
        pq.push({ d[st], st });

        while (!pq.empty()) {
            auto [cd, cur] = pq.top(); pq.pop();
            if (cd > d[cur]) continue;

            for (auto& nn : adj[cur]) {
                auto [nd, nxt, line] = nn;
                if (d[nxt] <= nd + cd) continue;

                d[nxt] = nd + cd;
                pre[nxt] = cur; p[nxt] = line;
                pq.push({ d[nxt], nxt });
            }
        }
    }

    T ret(ll n) {
        return d[n];
    }
};
set <ll> result;

int main() {
    fastio;

    cin >> n >> m; _dij dij(n); 
    for(int i = 1;i <= m;i++){
        ll a, b, c; cin >> a >> b >> c;
        dij.add(a, b, c, i);
    }
    dij.init(1);

    for(int i = n;i >= 1;i--){
        ll cur = i;
        while(cur != 1){
            if(result.count(p[cur])) break;
            result.insert(p[cur]);
            cur = dij.pre[cur];
        }
    }

    for(auto& i : result) cout << i << " ";
    
    

    return 0;
}
