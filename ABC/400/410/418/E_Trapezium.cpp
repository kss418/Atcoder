#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 2010; // SET MAX SIZE
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

vector <pll> cnt, num;
void run(){
    cin >> n; _gcd gcd;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            pll nxt = {a[i].x + a[j].x, a[i].y + a[j].y};
            num.push_back(nxt);
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            ll dx = a[i].x - a[j].x, dy = a[i].y - a[j].y;
            ll g = gcd.ret(dx, dy);
            dx /= g; dy /= g;
            
            cnt.push_back({dx, dy});
        }
    }

    ll result = 0;
    sort(all(cnt)); ll px = -1, py = -1, c = 0;
    for(auto& [x, y] : cnt){
        if(px != x || py != y) result += c * (c - 1) / 2, c = 0;
        c++; px = x; py = y;
    }
    result += c * (c - 1) / 2;

    sort(all(num));
    px = -1, py = -1, c = 0;
    for(auto& [x, y] : num){
        if(px != x || py != y) result -= c * (c - 1) / 2, c = 0;
        c++; px = x; py = y;
    }
    result -= c * (c - 1) / 2;

    cout << result << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}