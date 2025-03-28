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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll d[MAX][MAX][2], dn[2] = {-1, 1};

bool outrange(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cy >= n || cx >= m) return 1;
    if(st[cy][cx] == '#') return 1;
    return 0;
}

class node{
public:
    ll y, x, t;
};

void bfs(ll cy, ll cx){
    deque <pair <node, ll>> q;
    q.push_back({{cy, cx, 0}, 0});
    q.push_back({{cy, cx, 1}, 0});

    while(!q.empty()){
        auto[cn, cd] = q.front(); q.pop_front();
        auto[cy, cx, ct] = cn;
        if(d[cy][cx][ct] <= cd) continue;
        d[cy][cx][ct] = cd;

        if(!ct){
            for(int i = 0;i < 2;i++){
                ll ny = cy + dn[i];
                if(outrange(ny, cx)) continue;
                q.push_back({{ny, cx, ct ^ 1}, cd + 1});
            }
        }
        else{
            for(int i = 0;i < 2;i++){
                ll nx = cx + dn[i];
                if(outrange(cy, nx)) continue;
                q.push_back({{cy, nx, ct ^ 1}, cd + 1});
            }
        }
    }
}

void run(){
    cin >> n >> m;
    ll sy, sx, ey, ex;
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < m;j++){
            if(st[i][j] == 'S') sy = i, sx = j;
            else if(st[i][j] == 'G') ey = i, ex = j;
        }
    }

    memset(d, 0x3f, sizeof(d)); bfs(sy, sx);
    ll ret = min(d[ey][ex][0], d[ey][ex][1]);

    if(ret >= INF) cout << -1;
    else cout << ret;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
