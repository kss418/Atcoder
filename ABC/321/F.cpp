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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX];

void run(){
    cin >> n >> m; dp[0] = 1;
    for(int i = 1;i <= n;i++){
        char c; ll v; cin >> c >> v;
        if(c == '+'){
            for(int i = m;i >= v;i--){
                dp[i] += dp[i - v];
                dp[i] %= MOD;
            }
        }
        else{
            for(int i = v;i <= m;i++){
                dp[i] -= dp[i - v] % MOD;
                dp[i] = (dp[i] + MOD) % MOD;
            }
        }

        cout << dp[m] << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

