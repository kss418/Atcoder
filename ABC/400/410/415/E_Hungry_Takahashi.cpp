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
constexpr ll MAX = 401010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <vector <ll>> a, dp;
ll b[MAX], result;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        dp.assign(n + 1, vector<ll>(m + 1, MINF));
        dp[0][1] = dp[1][0] = cur;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j] - b[i + j - 1]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j] - b[i + j - 1]);
                if(dp[i][j] < 0) dp[i][j] = MINF;
            }
        }

        return dp[n][m] >= 0;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m; _bs <ll> bs(0ll, 2e15);
    a.resize(n + 1, vector<ll>(m + 1));
    dp.resize(n + 1, vector<ll>(m + 1, MINF));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }
    for(int i = 1;i <= n + m;i++) cin >> b[i];

    cout << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

