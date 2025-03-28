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
ll a[MAX], p[MAX], b[MAX], q[MAX];

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll use = 0;
        for(int i = 1;i <= n;i++){
            ll mn = INF;
            for(int j = 0;j <= b[i];j++){
                ll now = 0, req = cur;
                now += j * p[i];
                req -= j * a[i]; req = max(req, 0ll);
                now += (req / b[i]) * q[i];
                if(req % b[i]) now += q[i];
                mn = min(mn, now);
            }

            for(int j = 0;j <= a[i];j++){
                ll now = 0, req = cur;
                now += j * q[i]; 
                req -= j * b[i]; req = max(req, 0ll);
                now += (req / a[i]) * p[i];
                if(req % a[i]) now += p[i];
                mn = min(mn, now);
            }
            use += mn;
        }

        return use <= m;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) >> 1;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i] >> p[i] >> b[i] >> q[i];
    
    _bs bs(0, 1e10);
    cout << bs.ret();


    return 0;
}
