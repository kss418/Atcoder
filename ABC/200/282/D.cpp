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
vector <ll> adj[MAX], arr[MAX];
ll b[MAX], c[MAX], flag[MAX], sum;


void dfs(ll cur, ll pre, ll cnt, ll num){
    if(c[cur]){
        if(c[cur] != cnt) flag[num] = 1;
        return;
    }
    arr[num].push_back(cur);
    c[cur] = cnt; if(cnt == 1) b[num]++;

    for(auto& nxt : adj[cur]) {
        if(pre == nxt) continue;
        dfs(nxt, cur, cnt * -1, num);
    }
}

int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll cur = 1;
    for(int i = 1;i <= n;i++){
        if(c[i]) continue;
        dfs(i, -1, 1, cur++);
    }
    ll result = 0;

    for(int i = 1;i < cur;i++){
        if(flag[i]) break;
        sum += arr[i].size();
    }

    for(int i = 1;i < cur;i++){
        if(flag[i]) { result = 0; break; }
        result += (sum - arr[i].size()) * arr[i].size();
        sum -= arr[i].size();
        for(auto& j : arr[i]) {
            if(c[j] == 1) continue;
            result += b[i] - adj[j].size();
        }
    }

    cout << result;


    return 0;
}
