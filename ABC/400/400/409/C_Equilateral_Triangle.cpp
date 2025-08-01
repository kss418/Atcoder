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
ll cnt[MAX], a[MAX];

void run(){
    cin >> n >> m; ll cur = 0; cnt[0]++;
    for(int i = 1;i < n;i++){
        cin >> a[i];
        cur += a[i]; cur %= m;
        cnt[cur]++;
    }

    ll result = 0;
    if(m % 3){
        cout << 0; return;
    }

    for(int i = 0;i < m / 3;i++){
        result += cnt[i] * cnt[i + m / 3] * cnt[i + (2 * m) / 3];
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

