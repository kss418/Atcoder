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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ull c[MAX], sum[MAX], all[MAX], dp[MAX];
vector <ll> adj[MAX];

void dfs(ll cur, ll pre = -1){
    sum[cur] = c[cur];
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue; dfs(nxt, cur);
        sum[cur] += sum[nxt];
        all[cur] += sum[nxt] + all[nxt];
    }
}

ull solve(ll cur, ull s, ull a, ll pre = -1){
    dp[cur] = all[cur] + a;
    ull ret = dp[cur];
    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue;
        ull ns = s + sum[cur] - sum[nxt];
        ull na = a + all[cur] - all[nxt] - sum[nxt] + ns;
        ret = min(ret, solve(nxt, ns, na, cur));
    }

    return ret;
}


int main() {
    fastio;

    cin >> n;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e); 
        adj[e].push_back(s);
    }
    for(int i = 1;i <= n;i++) cin >> c[i]; dfs(1);

    cout << solve(1, 0, 0);

     
    return 0;
}
