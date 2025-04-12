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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 1e9;
ll a[MAX], sum[MAX];

void run(){
    cin >> n >> m;
    for(int i = 0;i <= n;i++){
        if(i < m) a[i] = 1;
        else a[i] = (sum[i - 1] - (i == m ? 0 : sum[i - m - 1]) + MOD) % MOD;
        sum[i] = (sum[i - 1] + a[i]) % MOD;;
    }

    cout << a[n] % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

