#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][11], c[MAX], dp[MAX][6 * 6 * 6 * 6 * 6 + 11];
ll cal(vector <ll>& now){
    ll ret = 0;
    for(int i = 0;i < m;i++) ret *= 6, ret += now[i];
    return ret;
}

ll solve(ll cur, vector <ll> now){
    ll num = cal(now);
    ll& ret = dp[cur][num];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret;

    ret = min(ret, solve(cur - 1, now));
    for(int i = 0;i < m;i++) now[i] = max(now[i] - a[cur][i + 1], 0ll);
    ret = min(ret, solve(cur - 1, now) + c[cur]);

    return ret;
}

void run(){
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp)); dp[0][0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    vector <ll> now;
    for(int i = 1;i <= m;i++) now.push_back(k);
    ll ret = solve(n, now);
    cout << (ret >= INF ? -1 : ret);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

