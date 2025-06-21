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

void run(){
    cin >> s; bool b = 0, k = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'B') b ^= i & 1;
        if(s[i] == 'K'){
            ll l = -1, r = -1;
            for(int j = 0;j < s.size();j++){
                if(s[j] != 'R') continue;
                if(l == -1) l = j;
                else r = j;
            }

            if(i > l && i < r) k = 1;
        }
    }

    cout << (b & k ? "Yes" : "No");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
