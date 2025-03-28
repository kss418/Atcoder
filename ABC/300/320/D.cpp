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
ll arr[MAX], ind[MAX];
ll rx[MAX], ry[MAX], v[MAX];

class node{
public:
    ll nxt, dx, dy;
};
vector <node> adj[MAX], org[MAX];

void dfs(ll cur, ll cx, ll cy){
    if(v[cur]) return; v[cur] = 1;
    rx[cur] = cx; ry[cur] = cy;

    for(auto& i : adj[cur]){
        auto[nxt, dx, dy] = i;
        dfs(nxt, cx + dx, cy + dy);
    }
}

int main() {
    fastio;

    memset(rx, 0x3f, sizeof(rx));
    memset(ry, 0x3f, sizeof(ry));

    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        adj[a].push_back({b, x, y});
        adj[b].push_back({a, -x, -y});
        org[a].push_back({b, x, y});
    }

    dfs(1, 0, 0);
    for(int i = 1;i <= n;i++){
        for(auto& j : org[i]){
            auto[nxt, dx, dy] = j;
            if(rx[nxt] != rx[i] + dx) rx[nxt] = -INF;
            if(ry[nxt] != ry[i] + dy) rx[nxt] = -INF;
        }
    }

    for(int i = 1;i <= n;i++){
        if(abs(rx[i]) == INF) cout << "undecidable\n";
        else cout << rx[i] << " " << ry[i] << '\n';
    }


    return 0;
}
