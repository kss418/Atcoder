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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 301010;
constexpr ll MOD = 998244353;
ll sum[MAX], now;

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll cnt = (cur / n) * sum[n];
        ll mod = cur % n;
        cnt += sum[mod];

        return cnt - now <= k;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) >> 1ll;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

int main() {
    fastio;

    cin >> n >> m >> k >> s;
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1];
        if(s[i - 1] == 'x') sum[i]++;
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        now = sum[i - 1];
        _bs bs(i, n * m);
        result = max(result, (bs.ret() - i + 1));
    }

    cout << result;


    return 0;
}
