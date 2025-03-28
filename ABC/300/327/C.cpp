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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
ll cy[MAX][10], cx[MAX][10], cn[MAX][10];

bool chk(){
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            if(cy[i][j] != 1) return 0;
            if(cx[i][j] != 1) return 0;
            if(cn[i][j] != 1) return 0;
        }
    }
    
    return 1;
}

void run(){
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++) {
            cin >> a[i][j]; a[i][j]--;
            cy[i][a[i][j]]++;
            cx[j][a[i][j]]++;
            ll num = 3 * (i / 3) + j / 3;
            cn[num][a[i][j]]++;
        }
    }

    cout << (chk() ? "Yes" : "No");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
