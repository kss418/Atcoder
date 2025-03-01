#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll mn = INF, all;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        ll mx = min(cur, a[1].x), mn = max(cur - a[1].y, 0ll);
        for(int i = 2;i <= n;i++){
            mx = min(mx + m, min(a[i].x, cur));
            mn = max(mn - m, max(cur - a[i].y, 0ll));
            if(mx < mn) return 0;
        }
        return 1;
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

ll cal(ll num){
    ll ret = 0;
    for(int i = 1;i <= n;i++){
        ret += a[i].x + a[i].y - num;
    }
    return ret;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        mn = min(mn, a[i].x + a[i].y);
    }

    _bs <ll> bs(0, mn);
    ll ret = bs.ret();
    cout << cal(ret);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

