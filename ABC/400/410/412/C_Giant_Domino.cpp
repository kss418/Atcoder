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
ll a[MAX];
multiset <ll> num;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    num.clear();
    for(int i = 2;i < n;i++) num.insert(a[i]);
    num.insert(MINF);
    

    ll now = a[1], result = 2;
    while(2 * now < a[n]){
        ll nxt = *--num.upper_bound(2 * now);
        if(nxt <= now){
            result = -1; break;
        }

        now = nxt;
        result++;
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

