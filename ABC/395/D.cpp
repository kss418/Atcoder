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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll pos[MAX], num[MAX], org[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        pos[i] = num[i] = org[i] = i;
    }

    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll idx, v; cin >> idx >> v;
            pos[idx] = org[v];
        } 
        else if(op == 2){
            ll a, b; cin >> a >> b;
            swap(org[a], org[b]);
            a = org[a]; b = org[b];
            swap(num[a], num[b]);
        } 
        else{
            ll idx; cin >> idx;
            cout << num[pos[idx]] << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

