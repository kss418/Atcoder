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
set <ll> result;

void run(){
    cin >> n;
    ll mul = 1, pl = 1, sq = sqrtl(abs(4 * n)) + 1;
    while(sq--){
        if((n - pl) % mul == 0) result.insert((n - pl) / mul);
        mul += 2; pl += mul;
    }

    mul = -1, pl = 0, sq = sqrtl(abs(4 * n)) + 1;
    while(sq--){
        if((n - pl) % (-mul) == 0) result.insert((n - pl) / mul);
        pl -= mul; mul -= 2; 
    }

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}