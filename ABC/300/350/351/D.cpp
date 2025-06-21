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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll v[MAX][MAX], cnt;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
ll sz[MAX * MAX];

bool outrange(ll cy, ll cx){
    return (cy < 0 || cx < 0 || cy >= n || cx >= m);
}

void dfs(ll cy, ll cx, ll num){
    if(v[cy][cx]) return;
    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        if(outrange(ny, nx)) continue;
        if(st[ny][nx] == '#') return;
    }

    v[cy][cx] = num; sz[num]++;
    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        if(outrange(ny, nx)) continue;
        if(st[ny][nx] == '#') continue;
        dfs(ny, nx, num);
    }
}

void pl(ll cy, ll cx){
    set <ll> arr;
    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        if(outrange(ny, nx)) continue;
        if(st[ny][nx] == '#') continue;
        arr.insert(v[ny][nx]);
    }

    for(auto& i : arr) sz[i]++;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(v[i][j] || st[i][j] == '#') continue;
            dfs(i, j, ++cnt);
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '#' || v[i][j]) continue;
            pl(i, j);
        }
    }

    ll result = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) if(st[i][j] == '.') result = 1;
    }

    for(int i = 1;i <= cnt;i++) result = max(result, sz[i]);
    cout << result;

     
    return 0;
}
