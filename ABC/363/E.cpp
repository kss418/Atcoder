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
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
ll arr[MAX][MAX], out[MAX][MAX], v[MAX][MAX];
vector <pll> h[101010];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            cin >> arr[i][j];
            h[arr[i][j]].push_back({i,j});
        }
    }

    deque <pll> q;
    for(int i = 1;i <= n;i++){
        out[i][1] = out[i][m] = 1;
    }

    for(int i = 2;i < m;i++){
        out[1][i] = out[n][i] = 1;
    }

    ll result = n * m;
    for(int i = 1;i <= k;i++){
        for(auto& j : h[i]) {
            auto [y, x] = j;
            if(!out[y][x] || v[y][x]) continue;
            q.push_back(j);
        }

        while(!q.empty()){
            auto [cy, cx] = q.front();
            q.pop_front(); 
            if(v[cy][cx]) continue;
            v[cy][cx] = 1; result--;

            for(int j = 0;j < 4;j++){
                ll nx = dx[j] + cx, ny = dy[j] + cy;
                if(nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
                out[ny][nx] = 1;
                if(v[ny][nx]) continue;
                
                if(arr[ny][nx] <= i) q.push_back({ny, nx});
            }
        }
        
        cout << result << "\n";
    }


    return 0;
}
