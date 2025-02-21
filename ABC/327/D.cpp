#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], num[MAX], result = 1;
vector <ll> adj[MAX];

void dfs(ll cur, ll now, ll pre = -1){
    if(num[cur] != -1){
        if(num[cur] != now) result = 0;
        return;
    }
    num[cur] = now;

    for(auto& nxt: adj[cur]){
        if(pre == nxt) continue;
        dfs(nxt, now ^ 1, cur);
    }
}

void run(){
    cin >> n >> m; memset(num, -1, sizeof(num));
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) {
        cin >> b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    for(int i = 1;i <= n;i++){
        if(num[i] != -1) continue;
        dfs(i, 0);
    }

    cout << (result ? "Yes" : "No");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
