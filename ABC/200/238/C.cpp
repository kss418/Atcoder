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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

class _gcd {
public:
    _gcd() {}

    tuple <ll, ll, ll> init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
};



int main() {
    fastio;

    cin >> n; _gcd gcd;
    ll result = 0;

    ll cur = 1;
    for(ll i = 1;i <= 18;i++){
        ll r = min<ll>(10 * cur - 1, n);
        ll l = cur - 1;
        if(r <= l) continue;

        ll a = (r - l) % MOD, b = (r - l + 1) % MOD;
        ll c = (a * b) % MOD * gcd.inv(2 , MOD) % MOD;
        result += c % MOD; result %= MOD; cur *= 10;
    }

    cout << result % MOD;
    

    return 0;
}
