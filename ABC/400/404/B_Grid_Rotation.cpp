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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string a[MAX], b[MAX];
char tmp[MAX][MAX];

void rotate(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) tmp[j][n - i - 1] = a[i][j];
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) a[i][j] = tmp[i][j];
    }
}

ll chk(){
    ll ret = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) ret += (a[i][j] != b[i][j]);
    }
    return ret;
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];

    ll result = INF;
    for(int i = 0;i < 4;i++){
        result = min(result, chk() + i);
        rotate();
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

