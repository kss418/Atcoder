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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class node{
public:
    ll nxt, b, c;
};
vector <node> adj[MAX];
ld dp[MAX];

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        for(int i = 1;i <= n;i++) dp[i] = -1e12; dp[1] = 0;
        for(int i = 1;i <= n;i++){
            for(auto&[nxt, b, c] : adj[i]){
                dp[nxt] = max(dp[nxt], dp[i] + b - c * cur);
            }
        }

        return dp[n] >= 0;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi - lo > 1e-9) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m;
    while(m--){
        ll s, e, b, c; cin >> s >> e >> b >> c;
        adj[s].push_back({e, b, c});
    }

    _bs <ld> bs(0, 10101);
    cout.precision(20);
    cout << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}