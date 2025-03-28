#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][2];
ll a, b, p, q;

class _inv {
public:
    _inv() {}
    ll pow_mod(ll a, ll b, ll c) {
        if (!b) return 1;
        ll ret = pow_mod(a, b / 2, c) % c;

        if (b % 2) return ((ret * ret) % c * (a % c)) % c;
        return (ret * ret) % c;
    }

    ll prime_inv(ll a, ll b) {
        return pow_mod(a, b - 2, b);
    }

    ll ret(ll a, ll b, ll m) { // (a * b^-1) % m 반환 m == prime
        return (a % m * prime_inv(b, m) % m) % m;
    }
};

ll solve(ll ap, ll bp, ll seq){
    ll& ret = dp[ap][bp][seq];
    if(ret != -1) return ret;
    ret = 0; _inv inv;

    if(seq){
        for(int i = 1;i <= q;i++) ret += solve(ap, min(bp + i, n), 0);
        ret *= inv.ret(1, q, MOD);
    }
    else{
        for(int i = 1;i <= p;i++) ret += solve(min(ap + i, n), bp, 1);
        ret *= inv.ret(1, p, MOD);
    }

    return ret %= MOD;
}


int main() {
    fastio;

    cin >> n >> a >> b >> p >> q;
    
    memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= 1;j++){
            dp[i][n][j] = 0;
            dp[n][i][j] = 1;
        }
    }

    cout << solve(a, b, 0);


    return 0;
}
