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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[2 * MAX], cnt[101];
vector <ll> adj[2 * MAX];

bool chk(){
    for(int i = 0;i < m;i++){
        if(cnt[i] < 2) return 0;
    } 
    return 1;
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = n;i < 2 * n;i++) a[i] = a[i - n];

    for(int i = 0;i < m;i++){
        ll sz; cin >> sz;
        for(int j = 1;j <= sz;j++){
            cin >> k; k--;
            adj[k].push_back(i);
            adj[k + n].push_back(i);
        }
    }

    ll result = INF;
    for(int i = 0;i < (1ll << 2 * n);i++){
        ll now = 0; memset(cnt, 0, sizeof(cnt));
        for(int j = 0;j < 2 * n;j++){
            if(!(i & (1ll << j))) continue;
            now += a[j];
            for(auto& nxt : adj[j]) cnt[nxt]++;
        }

        if(chk()) result = min(result, now);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

