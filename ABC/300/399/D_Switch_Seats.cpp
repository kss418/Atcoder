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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[2 * MAX];
bool ban[2 * MAX];
map <pll, ll> num;

void run(){
    cin >> n; num.clear();
    for(int i = 1;i <= 2 * n;i++){
        cin >> a[i]; ban[i] = 0;
    }

    ll result = 0, cnt = 0;
    for(int i = 2;i <= 2 * n;i++){
        ll mn = min(a[i - 1], a[i]);
        ll mx = max(a[i - 1], a[i]);
        if(a[i] == a[i - 1]){
            ban[a[i]] = 1;
            continue;
        }

        if(num.count({mn, mx})){
            if(num[{mn, mx}] == i - 1) continue;
            if(ban[mn] || ban[mx]) continue;
            result++;
        }
        else num[{mn, mx}] = i;
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

