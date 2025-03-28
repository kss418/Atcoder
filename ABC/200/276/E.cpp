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
constexpr ll MAX = 1010101;
constexpr ll MOD = 998244353;
vector <string> st;
ll h, w, flag;
vector <vector <ll>> v;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void dfs(ll cy, ll cx, ll num){
    if(cy < 0 || cx < 0 || cx >= w || cy >= h) return;
    if(st[cy][cx] != '.') return;
    if(v[cy][cx] & (1ll << num)) return; v[cy][cx] |= (1ll << num);
    if(v[cy][cx] & ~(1ll << num)) flag = 1;

    for(int i = 0;i < 4;i++) dfs(cy + dy[i], cx + dx[i], num);
}

int main() {
    fastio;

    cin >> h >> w; ll cx, cy;
    st.resize(h);
    v.resize(h, vector<ll>(w, 0));

    for(int i = 0;i < h;i++) {
        cin >> st[i];
        for(int j = 0;j < w;j++) if(st[i][j] == 'S') cy = i, cx = j;
    }
        
    for(int i = 0;i < 4;i++) dfs(cy + dy[i], cx + dx[i], i);
    if(flag) cout << "Yes";
    else cout << "No";
    

    return 0;
}
