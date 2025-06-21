#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 11;
constexpr ll MOD = 998244353;
string st[MAX];
ll result;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool v[MAX][MAX];

void solve(ll cy, ll cx, ll cnt){
    if(st[cy][cx] == '#') return;
    if(cnt == 0) {
        result++; return;
    }

    for(int i = 0;i < 4;i++){
        ll ny = dy[i] + cy, nx = dx[i] + cx;
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

        if(v[ny][nx]) continue;
        v[ny][nx] = 1;
        solve(ny, nx, cnt - 1);
        v[ny][nx] = 0;
    }
}

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '#') continue;
            memset(v, 0, sizeof(v));
            v[i][j] = 1;
            solve(i, j, k);
        }
    }
    
    cout << result;


    return 0;
}

