#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], w[MAX], dp[MAX];
vector <ll> adj[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;
    
    ll sz = adj[cur].size();
    vector <vector <ll>> ks;
    ks.resize(sz + 1, vector <ll>(MAX)); ks[0][0] = 1;
    for(int i = 1;i <= sz;i++){
        ll nxt = adj[cur][i - 1];
        for(int j = 0;j < w[cur];j++){
            ks[i][j] = max(ks[i][j], ks[i - 1][j]);
            if(j >= w[nxt]) {
                ks[i][j] = max(ks[i][j], ks[i - 1][j - w[nxt]] + solve(nxt));
            }
        }
    }

    ll mx = 0;
    for(int i = 0;i < w[cur];i++) {
        mx = max(mx, ks[sz][i]);
    }
    
    return ret += mx;
}

void run(){
    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i = 1;i <= n;i++) cin >> w[i];
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll result = 0; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) result += solve(i) * a[i];

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
