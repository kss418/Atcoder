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

constexpr ll INF = 1e9;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

void run(){
    cin >> n >> m;
    bool flag = 1;
    i128 sum = 0, num = 1;
    for(int i = 0;i <= m;i++){
        sum += num;
        num *= n;
        if(sum > INF) flag = 0;
    }

    if(!flag) cout << "inf";
    else cout << (ll)(sum);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

