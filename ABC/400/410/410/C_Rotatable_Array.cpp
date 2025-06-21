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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], pl;

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) a[i] = i + 1;
    while(m--){
        ll op, idx; cin >> op >> idx;
        if(op == 1){
            ll x; cin >> x;
            a[(idx + pl + n - 1) % n] = x;
        }
        else if(op == 2){
            cout << a[(idx + pl + n - 1) % n] << "\n";
        }
        else{
            pl += idx; pl %= n;
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

