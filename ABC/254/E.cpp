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
constexpr ll MAX = 151010;
constexpr ll MOD = 998244353;
vector <pll> adj[MAX]; ll d[MAX]; 
priority_queue <pll, vector<pll>, greater<pll>> pq;
vector <ll> arr; 

int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back({1, e});
        adj[e].push_back({1, s});
    }

    cin >> k; memset(d, 0x3f, sizeof(d));
    while(k--){
        ll x, now; cin >> x >> now;
        ll ret = 0; 
        d[x] = 0; pq.push({ d[x], x });

        while (!pq.empty()) {
            auto [cd, cur] = pq.top(); pq.pop();
            if (cd > d[cur]) continue;
            arr.push_back(cur);

            if (cd == now) continue; 
            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (d[nxt] <= nd + cd) continue;

                d[nxt] = nd + cd;
                pq.push({ d[nxt], nxt });
            }
        }

        while(!arr.empty()) {
            d[arr.back()] = INF;
            ret += arr.back(), arr.pop_back();
        }

        while(!pq.empty()) {
            d[pq.top().y] = INF; pq.pop();
        }

        cout << ret << "\n";
    }
    

    return 0;
}
