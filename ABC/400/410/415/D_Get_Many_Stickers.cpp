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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll result;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + m + 1, [](pll l, pll r){
        return l.x - l.y < r.x - r.y;
    });

    for(int i = 1;i <= m;i++){
        ll cnt = a[i].x - a[i].y;
        ll diff = n - a[i].x;
        if(diff < 0) continue;
        ll div = (diff ? diff / cnt : 0) + 1;

        result += div;
        n -= cnt * div;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

