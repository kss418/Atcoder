#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;

mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
pll a[MAX];

class _ccw{
public:
    _ccw() {}
    
    ll ret(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
        return ret({x1, y1}, {x2, y2}, {x3, y3});
    }
    ll ret(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);
    
        if(num > 0) return 1; 
        else if(num < 0) return -1; 
        return 0;
    }
} ccw;

ll cnt(pll l, pll r){
    ll ret = 0;
    for(int i = 1;i <= n;i++){
        ret += (ccw.ret(l, a[i], r) == 0);
    }
    return ret;
}

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

void run(){
    cin >> n; _gcd gcd;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    uniform_int_distribution <int> rnd(1, n);

    for(int i = 1;i <= 100;i++){
        ll l = rnd(rd), r = rnd(rd);
        while(l == r) r = rnd(rd);

        if(cnt(a[l], a[r]) >= (n + 1) / 2){
            cout << "Yes" << "\n";
            ll dx = a[l].x - a[r].x, dy = a[l].y - a[r].y;
            ll g = gcd.ret(abs(dx), abs(dy));
            dx /= g; dy /= g;
            if(dx < 0) dx *= -1, dy *= -1;
            dy *= -1;

            ll c = dy * a[l].x + dx * a[l].y;
            cout << dy << " " << dx << " " << -c;
            return;
        }
    }

    cout << "No";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}