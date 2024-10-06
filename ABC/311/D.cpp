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
constexpr ll MAX = 201;
constexpr ll MOD = 998244353;
string st[MAX];
bool v[MAX][MAX][4], use[MAX][MAX];
ll result, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};


void dfs(ll cy, ll cx, ll dir){
    if(cy < 0 || cx < 0 || cy >= n || cx >= m) return;
    if(st[cy][cx] == '#') return;
    if(v[cy][cx][dir]) return;
    if(!use[cy][cx]) {
        result++;
    }
    v[cy][cx][dir] = 1; use[cy][cx] = 1;
    ll ny = cy + dy[dir], nx = cx + dx[dir];
    
    if(st[ny][nx] == '.') dfs(cy + dy[dir], cx + dx[dir], dir);
    else for(int i = 0;i < 4;i++) {
        if(i == dir) continue;
        dfs(cy + dy[i], cx + dx[i], i);
    }
}


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < 4;i++) dfs(1, 1, i);

    cout << result;

    
    return 0;
}
