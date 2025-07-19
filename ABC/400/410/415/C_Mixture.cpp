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
constexpr ll MAX = 18; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[1ll << MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret;
    if(s[cur - 1] == '1') return ret = 0;

    for(int i = 0;i < n;i++){
        if(!(cur & (1ll << i))) continue;
        ll nxt = cur & ~(1ll << i);
        ret = max(ret, solve(nxt));
    }

    return ret;
}

void run(){
    cin >> n >> s;
    for(int i = 0;i <= s.size();i++) dp[i] = -1;
    dp[0] = 1;

    cout << (solve((1ll << n) - 1) ? "Yes" : "No") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

