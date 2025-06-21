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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
char result[MAX][MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= (n + 1) / 2;i++){
        char now = (i % 2 ? '#' : '.');
        for(int j = i;j <= n - i + 1;j++){
            result[i][j] = now;
            result[n - i + 1][j] = now;
            result[j][i] = now;
            result[j][n - i + 1] = now;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cout << result[i][j];
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

