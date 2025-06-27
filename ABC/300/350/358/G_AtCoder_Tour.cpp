#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], cy, cx, dp[MAX][MAX][10101];
ll dx[5] = {0, 0, -1, 1, 0}, dy[5] = {1, -1, 0, 0, 0};

bool outrange(ll cy, ll cx){
    return cy <= 0 || cx <= 0 || cy > n || cx > m;
}

ll solve(ll cy, ll cx, ll ct){
    ll& ret = dp[cy][cx][ct];
    if(ret != INF) return ret; ret = MINF;
    if(!ct) return ret;
    
    for(int i = 0;i < 5;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        if(outrange(ny, nx)) continue;
        ret = max(ret, solve(ny, nx, ct - 1) + a[cy][cx]);
    }

    return ret;
}

void run(){
    cin >> n >> m >> k;
    cin >> cy >> cx;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[cy][cx][0] = 0;

    ll result = 0;
    for(ll i = 1;i <= min(k, 10000ll);i++){
        ll diff = k - i;
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= m;k++){
                ll now = diff * a[j][k];
                now += solve(j, k, i);

                result = max(result, now);
            }
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}