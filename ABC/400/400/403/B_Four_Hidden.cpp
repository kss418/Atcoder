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
string a, b; 

bool chk(ll idx){
    for(int i = idx;i < idx + b.size();i++){
        if(i >= a.size()) return 0;
        if(a[i] == '?') continue;
        if(a[i] != b[i - idx]) return 0;
    }
    return 1;
}

void run(){
    cin >> a >> b; ll result = 0;

    for(int i = 0;i < a.size();i++){
        if(chk(i)) result = 1;
    }

    cout << (result ? "Yes" : "No");
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

