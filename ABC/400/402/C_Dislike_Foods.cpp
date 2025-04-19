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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll sz[MAX], b[MAX], result;
vector <ll> a[MAX];

void run(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        cin >> sz[i];
        for(int j = 0;j < sz[i];j++){
            cin >> k; a[k].push_back(i);
        }
    }

    for(int i = 0;i < n;i++){
        cin >> b[i];
        for(auto& j : a[b[i]]){
            if(!--sz[j]) result++;
        }
        cout << result << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

