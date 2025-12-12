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
constexpr ll MAX = 1ll << 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], mx;

void dnc(ll l, ll r, ll mod){
    if(l > r) return;
    if(l == r){
        a[l] += mod;
        return;
    }

    ll mid = (l + r) >> 1ll;
    mx = max(mx, mod % 2);
    dnc(l, mid, mod / 2);
    dnc(mid + 1, r, mod / 2 + mod % 2);
}

void run(){
    cin >> n >> m; ll sz = 1ll << n;
    ll avg = m / sz, mod = m % sz;
    for(int i = 1;i <= sz;i++) a[i] = avg;
    dnc(1, sz, mod);

    cout << mx << "\n";
    for(int i = 1;i <= sz;i++) cout << a[i] << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}