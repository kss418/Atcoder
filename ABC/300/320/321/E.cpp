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
ll a[MAX];

void run(){
    cin >> n >> m >> k; ll result = 0;
    ll nn = -1, mn = -1;
    for(int i = 0;i < 63;i++){
        if(n & (1ll << i)) nn = i;
        if(m & (1ll << i)) mn = i;
    }

    if(mn + k <= nn){
        ll mn = m << k, mx = m;
        for(int i = 1;i <= k;i++) mx <<= 1ll, mx++;
        result += max(min(mx, n) - mn + 1, 0ll);
    }

    while(m > 1 && k){
        ll mod = m & 1;
        m >>= 1ll; k--;

        for(int i = 0;i < 63;i++){
            if(n & (1ll << i)) nn = i;
            if(m & (1ll << i)) mn = i;
        }
        if(mn + k > nn) continue;

        if(!k) result++;
        else{
            ll mn = m << 1ll, mx = m << 1ll;
            mn += (mod ^ 1); mx += (mod ^ 1);
            mn <<= (k - 1);
            for(int i = 1;i < k;i++) mx <<= 1ll, mx++;
            result += max(min(mx, n) - mn + 1, 0ll);
        }
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

