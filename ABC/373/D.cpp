#include <bits/stdc++.h>
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
vector <pll> adj[MAX];
ll result[MAX], v[MAX];

void dfs(ll cur, ll num){
    if(v[cur]) return;
    v[cur] = 1;
    result[cur] = num;
    for(auto& i : adj[cur]){
        dfs(i.x, num + i.y);
    }
}

int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll s,e,c;
        cin >> s >> e >> c;
        adj[s].push_back({e,c});
        adj[e].push_back({s,-c});
    }

    for(int i = 1;i <= n;i++){
        if(v[i]) continue;
        dfs(i, 0);
    }
    for(int i = 1;i <= n;i++) cout << result[i] << " ";
    
  
    return 0;
}
