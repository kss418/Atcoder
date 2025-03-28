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
ll a[MAX], b[MAX], sum[MAX];

void run(){
    cin >> n >> m >> k; ll cnt = n * m, result = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i];

    sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);
    for(int i = 1;i <= m;i++) sum[i] = sum[i - 1] + b[i];

    for(int i = 1;i <= n;i++){
        if(a[i] >= k) break;
        ll idx = upper_bound(b + 1, b + m + 1, k - a[i] - 1) - b - 1;
        result += a[i] * idx + sum[idx]; cnt -= idx;
    }

    cout << result + k * cnt;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
