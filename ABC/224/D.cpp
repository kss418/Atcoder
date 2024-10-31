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
vector <ll> a;
vector <ll> adj[MAX];
map <vector<ll>, ll> d;
deque <pair<vector <ll>, ll>> q;
vector <ll> en = { -1, 1, 2, 3, 4, 5, 6, 7, 8, 0 };

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    a.resize(10); a[0] = -1;
    for(int i = 1;i <= 8;i++) {
        cin >> k; a[k] = i;
    }

    q.push_back({a, 0});
    while(!q.empty()){
        auto[cur, cd] = q.front(); q.pop_front();
        if(d.count(cur) && d[cur] <= cd) continue;
        d[cur] = cd; if(cur == en) break;

        ll empty = -1;
        for(int i = 1;i <= 9;i++) if(!cur[i]) empty = i;

        for(auto& nxt : adj[empty]){
            swap(cur[empty], cur[nxt]);
            q.push_back({cur, cd + 1});
            
            swap(cur[empty], cur[nxt]);
        }
    }

    if(d.count(en)) cout << d[en];
    else cout << -1;
    

    return 0;
}

