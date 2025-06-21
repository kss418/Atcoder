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
constexpr ll MAX = 22; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], now, all, result;
bool use[MAX];
vector <ll> vec;

void bt(){
    result = max(result, all ^ now);
    if(vec.size() >= (n * m + 1) / 2){
        return;
    }

    for(int i = (vec.empty() ? 0 : vec.back() + 1);i < n * m;i++){
        if(i % m == m - 1 || use[i] || use[i + 1]) continue;
        use[i] = use[i + 1] = 1;
        now ^= a[i] ^ a[i + 1];
        vec.push_back(i); 
        bt();
        vec.pop_back();
        now ^= a[i] ^ a[i + 1];
        use[i] = use[i + 1] = 0;
    }

    for(int i = (vec.empty() ? 0 : vec.back() + 1);i < n * m;i++){
        if(i / m == n - 1 || use[i] || use[i + m]) continue;
        use[i] = use[i + m] = 1;
        now ^= a[i] ^ a[i + m];
        vec.push_back(i); 
        bt();
        vec.pop_back();
        now ^= a[i] ^ a[i + m];
        use[i] = use[i + m] = 0;
    }
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i * m + j];
            all ^= a[i * m + j];
        }
    }

    bt();
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

