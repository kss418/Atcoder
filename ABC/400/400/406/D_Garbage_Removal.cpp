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
pll a[MAX];
set <ll> sx[MAX], sy[MAX];

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++){
        cin >> a[i].x >> a[i].y;
        sx[a[i].x].insert(a[i].y);
        sy[a[i].y].insert(a[i].x);
    }

    ll q; cin >> q;
    while(q--){ 
        ll op, idx; cin >> op >> idx;
        if(op == 1){
            cout << sx[idx].size() << "\n";
            for(auto& y : sx[idx]){
                sy[y].erase(sy[y].find(idx));
            }
            sx[idx].clear();
        }
        else{
            cout << sy[idx].size() << "\n";
            for(auto& x : sy[idx]){
                sx[x].erase(sx[x].find(idx));
            }
            sy[idx].clear();
        }
    }   
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

