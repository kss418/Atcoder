#include <bits/stdc++.h>
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
constexpr ll MAX = 7; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll dp[1ll << MAX][1ll << MAX];

bool chk(ll cv, ll nv){
    for(int i = 0;i < m - 1;i++){
        bool c1 = (1ll << i) & cv, c2 = (1ll << (i + 1)) & cv;
        bool n1 = (1ll << i) & nv, n2 = (1ll << (i + 1)) & nv;
        if(c1 && n1 && c2 && n2) return 0;
    }

    return 1;
}

ll solve(ll cy, ll cv){
    if(cy < 0) return 0;
    ll& ret = dp[cy][cv];
    if(ret != -1) return ret; ret = INF;

    ll co = 0;
    for(int i = 0;i < m;i++){
        if(st[cy][i] == '#' && !((1ll << i) & cv)) co++;
        if(st[cy][i] == '.' && (1ll << i) & cv) return ret = INF;
    }

    for(ll nv = 0;nv < (1ll << m);nv++){
        if(!chk(cv, nv)) continue;
        ret = min(ret, solve(cy - 1, nv) + co);
    }

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> st[i];

    ll result = INF;
    for(int i = 0;i < (1ll << m);i++){
        result = min(result, solve(n - 1, i));
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}