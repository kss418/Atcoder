#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll v[MAX], a[MAX], c[MAX];
ll dp[MAX][MAX][3], mn[3];

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        mn[0] = mn[1] = mn[2] = 1e12;
        for(ll i = 0;i <= m;i++){
            for(ll j = 0;j < 3;j++) if(dp[n][i][j] >= cur) mn[j] = min(mn[j], i);
        }
        ll ret = mn[0] + mn[1] + mn[2];
        return ret <= m;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};


void run(){
    cin >> n >> m; _bs <ll> bs(0, 1e11);
    for(int i = 1;i <= n;i++) cin >> v[i] >> a[i] >> c[i];
    memset(dp, 0xc0, sizeof(dp));
    for(int i = 0;i < 3;i++) dp[0][0][i] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            for(int k = 0;k < 3;k++) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
            ll now = v[i] - 1;
            if(j >= c[i]) dp[i][j][now] = max(dp[i][j][now], dp[i - 1][j - c[i]][now] + a[i]);
        }
    }
    cout << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

