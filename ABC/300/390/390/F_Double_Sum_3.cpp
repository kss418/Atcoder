#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt, mi;
ll la[MAX], mx[MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++){
        cnt += (i - la[a[i]]) * (n - i + 1);
        la[a[i]] = i;
    }

    memset(la, 0, sizeof(la)); ll now = 0;
    for(ll i = 1;i <= n;i++){
        now += min(i, la[a[i] + 1]) - min(la[a[i]], la[a[i] + 1]);
        now += min(i, la[a[i] - 1]) - min(la[a[i]], la[a[i] - 1]);
        la[a[i]] = i;

        mi += now;
    }

    cout << cnt - mi;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}