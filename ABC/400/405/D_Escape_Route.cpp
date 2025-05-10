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
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll d[MAX][MAX], pre[MAX][MAX];

class node{
public:
    ll y, x, d;
};
deque <node> q;

bool outrange(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cy >= n || cx >= m) return 1;
    return st[cy][cx] == '#';
}

void run(){
    cin >> n >> m;
    memset(d, 0x3f, sizeof(d));
    memset(pre, -1, sizeof(pre));
    
    for(int i = 0;i < n;i++){
        cin >> st[i];
        for(int j = 0;j < m;j++){
            if(st[i][j] == '#') pre[i][j] = -2;
            if(st[i][j] != 'E') continue;
            d[i][j] = 0;
            q.push_back({i, j, 0});
        } 
    }

    while(!q.empty()){
        auto[cy, cx, cd] = q.front(); q.pop_front();
        if(cd > d[cy][cx]) continue;

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(d[ny][nx] <= cd + 1) continue;
            d[ny][nx] = cd + 1;
            pre[ny][nx] = i;
            q.push_back({ny, nx, cd + 1});
        }
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            ll now = pre[i][j];
            if(now == -1) cout << "E";
            else if(!now) cout << "<";
            else if(now == 1) cout << "^";
            else if(now == 2) cout << ">";
            else if(now == 3) cout << "v";
            else cout << "#";
        }
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

