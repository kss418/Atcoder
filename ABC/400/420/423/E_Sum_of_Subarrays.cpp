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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX]; i128 pre[MAX][3];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(ll i = 1;i <= n;i++){
        pre[i][0] = pre[i - 1][0] + a[i];
        pre[i][1] = pre[i - 1][1] + i * a[i];
        pre[i][2] = pre[i - 1][2] + i * i * a[i];
    } 

    while(m--){
        ll l, r; cin >> l >> r;
        i128 now = -(pre[r][2] - pre[l - 1][2]);
        now += (l + r) * (pre[r][1] - pre[l - 1][1]);
        now += (1 - l) * (r + 1) * (pre[r][0] - pre[l - 1][0]);
        cout << (ll)now << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}