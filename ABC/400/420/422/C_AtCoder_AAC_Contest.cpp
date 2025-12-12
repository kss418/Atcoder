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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

void run(){
    cin >> n >> m >> k;
    ll mn = min({n, m, k}), result = mn;
    n -= mn; m -= mn; k -= mn;

    if(n > k){
        ll d = min(n - k, k);
        result += d;
        n -= 2 * d; k -= d;
    }
    else{
        ll d = min(k - n, n);
        result += d;
        n -= d; k -= 2 * d;
    }
    
    mn = min(n, k);
    result += 2 * (mn / 3);
    n %= 3; k %= 3;

    if((n >= 2 && k >= 1) || (k >= 2 && n >= 1)) result++;
    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}