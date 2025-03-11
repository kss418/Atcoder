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
string a, b;

bool suf(){
    for(int i = 0;i < n;i++){
        if(a[n - i - 1] != b[m - i - 1]) break;
        if(i == n - 1) return 2;
    }
    return 0;
}

bool pre(){
    for(int i = 0;i < n;i++){
        if(a[i] != b[i]) break;
        if(i == n - 1) return 1;
    }
    return 0;
}

ll ret(){
    bool s = suf(), p = pre();
    if(s && p) return 0;
    else if(p) return 1;
    else if(s) return 2;
    return 3;
}

void run(){
    cin >> n >> m >> a >> b;
    cout << ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

