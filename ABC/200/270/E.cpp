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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], all;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        ll sum = 0;
        for(int i = 1;i <= n;i++) sum += min(cur, a[i]);

        return sum <= m;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m; _bs <ll> bs(0, 2e12);
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll ret = bs.ret();
    
    for(int i = 1;i <= n;i++) {
        m -= min(a[i], ret);
        a[i] = max(a[i] - ret, 0ll);
    }

    for(int i = 1;i <= n;i++){
        if(!m) break;
        if(a[i]) m--, a[i]--;
    }

    for(int i = 1;i <= n;i++) cout << a[i] << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
