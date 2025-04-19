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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
vector <ll> v1[MAX], v2[MAX];

void get1(ll cy, ll cx, ll now){
    if(cx > n || cy > n) return;
    if(cx + cy == n + 1){
        v1[cy].push_back(now);
        return;
    }

    now = (10 * now + a[cy][cx]) % m;
    get1(cy + 1, cx, now); get1(cy, cx + 1, now);
}

void get2(ll cy, ll cx, ll num, ll now){
    if(cy > n || cx > n) return;
    
    now = (10 * now + a[cy][cx]) % m;
    if(cy == n && cx == n){
        v2[num].push_back(now);
        return;
    }

    get2(cy + 1, cx, num, now); get2(cy, cx + 1, num, now);
}

void run(){
    cin >> n >> m; 
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    ll result = 0, mul = 1;
    for(int i = 1;i <= n;i++){
        get1(1, 1, 0);
        get2(i, n - i + 1, i, 0);
    }

    for(int i = 1;i <= n;i++) mul *= 10, mul %= m;
    for(int i = 1;i <= n;i++){
        sort(all(v1[i])); sort(all(v2[i]));
        for(auto& j : v1[i]){
            ll now = (j * mul) % m;
            auto ub = lower_bound(all(v2[i]), m - now);
            if(ub == v2[i].begin()) result = max(result, (*--v2[i].end() + now) % m);
            else result = max(result, (*--ub + now) % m);
        }
    }

    cout << result << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

