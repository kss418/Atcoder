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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][1010];
class node{
public:
    ll l, c, k;
}; node b[3];

void run(){
    cin >> n; memset(dp, 0x3f, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= 2;i++) cin >> b[i].l >> b[i].c >> b[i].k;
    if(b[2].c < b[1].c) swap(b[1], b[2]);

    for(int i = 0;i <= b[1].k;i++) dp[0][i] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= b[1].k;j++){
            for(int k = 0;k <= j;k++){
                ll now = max(a[i] - k * b[1].l, 0ll);
                ll cnt = now / b[2].l + (now % b[2].l ? 1 : 0);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + cnt);
            }
        }
    }

    ll result = INF;
    for(int i = 0;i <= b[1].k;i++){
        if(dp[n][i] > b[2].k) continue;
        result = min(result, b[1].c * i + b[2].c * dp[n][i]);
    }

    cout << (result == INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

