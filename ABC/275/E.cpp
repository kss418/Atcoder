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
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
ll dp[MAX][MAX], dv;

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

ll solve(ll cur, ll cnt){
    if(cnt > k) return 0;
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 1;i <= m;i++){
        if(cur + i > n){
            ret += solve(n - (cur + i - n), cnt + 1) % MOD * dv % MOD;
        }
        else {
            ret += solve(cur + i, cnt + 1) % MOD * dv % MOD;
        }
        ret %= MOD;
    }

    return ret;
}


int main() {
    fastio;

    cin >> n >> m >> k; _inv inv;
    ll result = 0; dv = inv.ret(1, m, MOD);
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= k;i++) dp[n][i] = 1;

    cout << solve(0, 0);


    return 0;
}
