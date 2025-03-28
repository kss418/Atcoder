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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
pll a[MAX];

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
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

_gcd g;
bool chk(pll a, pll b, pll c){
    ll dx1 = b.x - a.x;
    ll dx2 = c.x - b.x;
    ll dy1 = b.y - a.y;
    ll dy2 = c.y - b.y;

    if(!dy1 && !dy2) return 0;
    if(!dy1 || !dy2) return 1;

    ll g1 = g.ret(dx1, dy1);
    ll g2 = g.ret(dx2, dy2);
    dx1 /= g1; dy1 /= g1;
    dx2 /= g2; dy2 /= g2;

    if(dx1 != dx2 || dy1 != dy2) return 1;
    return 0;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1);

    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            for(int k = j + 1;k <= n;k++){
                result += chk(a[i], a[j], a[k]);
            }
        }
    }

    cout << result;
    
    
    return 0;
}
