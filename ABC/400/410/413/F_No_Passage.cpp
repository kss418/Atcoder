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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX];
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

class node{
public:
    ll y, x, v;
    bool operator < (const node& ot) const{
        return v > ot.v;
    }
};
priority_queue <node> pq;

bool outrange(ll cy, ll cx){
    return cy <= 0 || cx <= 0 || cy > n || cx > m;
}

void run(){
    cin >> n >> m >> k; memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= k;i++){
        ll y, x; cin >> y >> x;
        dp[y][x] = 0; pq.push({y, x, 0});     
    }
    
    while(!pq.empty()){
        auto& [cy, cx, v] = pq.top(); pq.pop();
        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            if(dp[ny][nx] <= v) continue;

            vector <ll> arr;
            for(int j = 0;j < 4;j++){
                ll nny = ny + dy[j], nnx = nx + dx[j];
                if(outrange(nny, nnx)) arr.push_back(INF);
                else arr.push_back(dp[nny][nnx]);
            }

            sort(all(arr));
            if(arr[1] + 1 >= dp[ny][nx]) continue;
            dp[ny][nx] = min(arr[1] + 1, INF);
            if(dp[ny][nx] != INF) pq.push({ny, nx, dp[ny][nx]});
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ll now = dp[i][j];
            result += (now >= INF ? 0 : now);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

