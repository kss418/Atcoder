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
vector <ll> adj[MAX];
deque <pll> q;
ll v[MAX];

int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
    }

    q.push_back({1, 0});
    while(!q.empty()){
        auto [cur, d] = q.front(); q.pop_front();
        v[cur] = 1;

        for(auto& nxt : adj[cur]){
            if(nxt == 1){
                cout << d + 1; return 0;
            }
            if(v[nxt]) continue;
            q.push_back({nxt, d + 1});
        }
    }

    cout << -1;
    

    return 0;
}
