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
constexpr ll MAX = 1010101;
constexpr ll MOD = 998244353;
set <ll> p; map<ll, ll> cnt;

class _bs { // 0-based index
public:
    ll l, r;
    _bs(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll ret = 1;
        for(auto& i : p){
            ll num = 0;
            if(i > sqrtl(10ll * k)) num = cur >= i;
            else for(ll j = i;j <= cur;j *= i){
                num += cur / j;
            }

            if(num < cnt[i]) ret = 0;
        }

        return ret;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo - 1) >> 1ll;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

int main() {
    fastio;

    
    cin >> k; _bs bs(2, k);

    ll cur = k;
    for(ll i = 2;i * i <= k;i++){
        while(cur % i == 0){
            cur /= i; p.insert(i);
            cnt[i]++;
        }
    }
    if(cur > 1) cnt[cur]++, p.insert(cur);

    cout << bs.ret();


    return 0;
}
