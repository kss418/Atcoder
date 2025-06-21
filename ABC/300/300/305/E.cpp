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
vector <ll> adj[MAX], result;
ll arr[MAX]; bool v[MAX];
pll num[MAX];

priority_queue <pll> pq;


int main() {
    fastio;

    cin >> n >> m >> k;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    memset(arr, -1, sizeof(arr));
    
    for(int i = 1;i <= k;i++) {
        ll p, h; cin >> p >> h;
        pq.push({h, p});
    }

    while(!pq.empty()){
        auto[cc, cur] = pq.top(); pq.pop();
        if(arr[cur] >= cc) continue;
        arr[cur] = cc;

        for(auto& nxt : adj[cur]){
            if(arr[nxt] >= cc - 1) continue;
            pq.push({cc - 1, nxt});
        }
    }

    for(int i = 1;i <= n;i++){
        if(arr[i] != -1) result.push_back(i);
    }

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";


    return 0;
}
