#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll d[MAX][MAX], sy, sx, ey, ex;
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

class node{
public:
    ll y, x, d;
    bool operator > (const node& ot) const{
        return d > ot.d;
    }
};
priority_queue <node, vector<node>, greater<node>> pq;

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

void run(){
    cin >> n >> m; memset(d, 0x3f, sizeof(d));
    for(int i = 0;i < n;i++) cin >> st[i];
    cin >> sy >> sx >> ey >> ex;
    sy--; sx--; ey--; ex--;

    pq.push({sy, sx, 0});
    pq.push({sy, sx, 1});
    while(!pq.empty()){
        auto[cy, cx, cd] = pq.top(); pq.pop();
        if(d[cy][cx] <= cd) continue;
        d[cy][cx] = cd;

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            pq.push({ny, nx, cd + (st[ny][nx] == '#')});
        }

        for(int i = 0;i < 4;i++){
            ll ny = cy + 2 * dy[i], nx = cx + 2 * dx[i];
            if(outrange(ny, nx)) continue;
            pq.push({ny, nx, cd + 1});
        }
    }

    cout << d[ey][ex];
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

