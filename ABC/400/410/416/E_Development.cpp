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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], d[MAX][MAX], ti;

void init() {
    for (int k = 1; k <= n + 1; k++) {
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= n + 1; j++) {
                if (d[i][j] <= d[i][k] + d[k][j]) continue;
                d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

void run(){
    cin >> n >> m; memset(d, 0x3f, sizeof(d));
    for(int i = 1;i <= n + 1;i++) d[i][i] = 0;
    for(int i = 1;i <= m;i++){
        ll s, e, c; cin >> s >> e >> c;
        d[s][e] = min(d[s][e], 2 * c);
        d[e][s] = min(d[e][s], 2 * c);
    }

    cin >> k >> ti;
    for(int i = 1;i <= k;i++){
        cin >> a[i]; 
        d[a[i]][n + 1] = d[n + 1][a[i]] = ti;
    }
    init();

    ll q; cin >> q;
    while(q--){
        ll op; cin >> op;
        if(op == 1){
            ll s, e, c; cin >> s >> e >> c;
            d[s][e] = min(d[s][e], 2 * c);
            d[e][s] = min(d[e][s], 2 * c);

            for(int i = 1;i <= n + 1;i++){
                for(int j = 1;j <= n + 1;j++){
                    ll now = min(d[i][s] + d[s][e], INF);
                    now = min(now + d[e][j], INF);
                    d[i][j] = min(d[i][j], now);
                    d[j][i] = min(d[j][i], now);
                }
            }
        }
        else if(op == 2){   
            ll idx; cin >> idx;
            d[idx][n + 1] = d[n + 1][idx] = ti;

            for(int i = 1;i <= n + 1;i++){
                for(int j = 1;j <= n + 1;j++){
                    ll now = min(d[i][idx] + d[idx][n + 1], INF);
                    now = min(now + d[n + 1][j], INF);
                    d[i][j] = min(d[i][j], now);
                    d[j][i] = min(d[j][i], now);
                }
            }
        }
        else{
            ll now = 0;
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++) now += (d[i][j] >= INF ? 0 : d[i][j]);
            }

            cout << now / 2 << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

