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
constexpr ll MAX = 22; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], l[1ll << MAX], cnt[1ll << MAX];

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
}; _gcd g;

ll cal(ll a, ll b){
    if(a > k || b > k) return k + 1;
    ll num = g.ret(a, b);
    i128 ret = (i128)a * (i128)b / (i128)num;
    if(ret > k) return k + 1;
    return (ll)ret;
}

ll comb[MAX][MAX], result;
void run(){
    cin >> n >> m >> k; l[0] = 1;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(ll i = 1;i < (1ll << n);i++){
        l[i] = cal(l[i & (i - 1)], a[ __builtin_ctz(i)]); 
        cnt[i] = cnt[i & (i - 1)] + 1;
    }
    
    for(int i = 1;i <= n;i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1;j < i;j++) comb[i][j] = comb[i - 1][j - 1] + comb[i  - 1][j];
    }

    for(int i = 1;i < (1ll << n);i++){
        if(l[i] > k || cnt[i] < m) continue;
        ll div = k / l[i], c = comb[cnt[i]][cnt[i] - m];
        result += c * div * ((cnt[i] - m) % 2 ? -1 : 1);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}