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
constexpr ll MAX = 301010;
constexpr ll MOD = 998244353;
ll a[MAX], same;
vector <ll> arr;
map <ll, bool> cnt;

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll use = upper_bound(all(arr), cur) - arr.begin();

        use += (same + arr.size() - use) >> 1;
        return use >= cur;
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

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(cnt[a[i]]) same++; 
        else arr.push_back(a[i]);
        cnt[a[i]] = 1;
    }
    sort(all(arr)); cnt.clear();

    _bs bs(0, 1e9 + 1);
    cout << bs.ret();


    return 0;
}
