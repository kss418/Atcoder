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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
string st[MAX];
ll result[MAX];

ll dfs(ll cx, ll cy, ll cnt, ll dir){
    if(cx < 0 || cy < 0 || cx >= m || cy >= n) return cnt - 1;
    if(st[cy][cx] == '.') return cnt - 1;
    ll ret = 0;
    if(dir == 0) ret = dfs(cx + 1, cy + 1, cnt + 1, dir);
    if(dir == 1) ret = dfs(cx - 1, cy + 1, cnt + 1, dir);
    if(dir == 2) ret = dfs(cx + 1, cy - 1, cnt + 1, dir);
    if(dir == 3) ret = dfs(cx - 1, cy - 1, cnt + 1, dir);
    
    return max(ret, 0ll);
}

int main() {
    fastio;

    cin >> n >> m; 
    for(int i = 0;i < n;i++) cin >> st[i];
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] != '#') continue;
            ll cur = INF;
            for(int k = 0;k < 4;k++) cur = min(cur, dfs(j, i, 0, k));
            result[cur]++;
        }
    }

    for(int i = 1;i <= min(n, m);i++) cout << result[i] << " ";


    return 0;
}
