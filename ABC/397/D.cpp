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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

void run(){
    cin >> n;
    for(i128 i = 1;i * i * i <= 4 * n;i++){
        i128 num = 3 * i * (4 * n - i * i * i);
        i128 sq = sqrtl(num);
        if(sq * sq != num) continue;

        ll hi = sq - 3 * i * i, lo = 6 * i;
        if(hi % lo) continue;
        hi /= lo; if(hi <= 0) continue;
        ll mx = hi + i;
        cout << mx << " " << hi; return;
    }
    
    cout << -1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

 
