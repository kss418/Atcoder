#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
vector <ll> a;

class _bs { // 0-based index
public:
    ll l, r, num;
    _bs(ll l, ll r, ll num) {
        this->l = l; this->r = r;
        this->num = num;
    }

    ll f(ll cur) {
        ll low = lower_bound(all(a), num - cur) - a.begin();
        ll hi = upper_bound(all(a), num + cur) - a.begin();

        ll cnt = hi - low;
        if (cnt >= k) return 1;
        return 0;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo - 1) >> 1;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

int main() {
    fastio;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k; a.push_back(k);
    }
    sort(all(a));

    while (m--) {
        ll b;
        cin >> b >> k;
        _bs bs(0, 2e8, b);
        
        cout << bs.ret() << "\n";
    }


    return 0;
}
