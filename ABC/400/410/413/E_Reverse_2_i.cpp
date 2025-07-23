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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], tmp[MAX];

ll dnc(ll l, ll r){
    if(l >= r) return a[l];
    ll mid = (l + r) / 2;
    ll lmn = dnc(l, mid); ll rmn = dnc(mid + 1, r);
    
    if(rmn < lmn){
        for(int i = l;i <= mid;i++) tmp[i] = a[mid + i - l + 1];
        for(int i = mid + 1;i <= r;i++) tmp[i] = a[l + i - mid - 1];
        for(int i = l;i <= r;i++) a[i] = tmp[i];
    }

    return min(lmn, rmn);
}

void run(){
    cin >> n;
    for(int i = 1;i <= (1ll << n);i++) cin >> a[i];
    dnc(1, (1ll << n));

    for(int i = 1;i <= (1ll << n);i++) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

