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
deque <pair <pll, ll>> q;
ll v[MAX][MAX], result;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool outrange(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cy >= n || cx >= m) return 1;
    if(st[cy][cx] == '#') return 1;
    return 0;
}

void bfs(){
    while(!q.empty()){
        auto[cur, cc] = q.front(); q.pop_front();
        auto[cy, cx] = cur;

        if(v[cy][cx] <= cc) continue; v[cy][cx] = cc;
        for(int i = 0;i < 4;i++){
            ll ny = dy[i] + cy, nx = dx[i] + cx;
            if(outrange(ny, nx)) continue;
            if(v[ny][nx] <= cc + 1) continue;
            q.push_back({{ny, nx}, cc + 1});
        }
    }
}

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) if(st[i][j] == 'H') q.push_back({{i, j}, 0});
    }
    memset(v, 0x3f, sizeof(v)); bfs();

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(v[i][j] > k) continue;
            result++;
        }
    }

    cout << result;

     
    return 0;
}
