#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];
class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll use = m;
        for (int i = 1; i <= n; i++) {
            if (arr[i] < cur) break;
            use -= arr[i] - cur + 1;
        }
        
        return use >= 0;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo - 1) >> 1;
            if (!f(mid)) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};

int main() {
    fastio;
    
    cin >> n >> m;
    ll mx = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i], mx = max(mx, arr[i]);
    sort(arr + 1, arr + n + 1);
    reverse(arr + 1, arr + n + 1);
    _bs bs(0, 2 * 1e9 + 1);

    ll num = bs.ret(), result = 0; 

    for (int i = 1; i <= n; i++) {
        if (arr[i] < num) break;
        ll diff = arr[i] - num + 1;
        result += arr[i] * (arr[i] + 1) / 2;
        result -= (num - 1) * num / 2;
        arr[i] = num - 1; m -= diff;
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] <= 0) break;
        if (arr[i] != num - 1) break;
        if (!m) break;
        result += num - 1; m--;
    }

    cout << result;
 

    return 0;
}
