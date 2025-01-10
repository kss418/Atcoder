#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

void run(){
    cin >> n >> m; vector <pll> result;
    for(int i = n;i >= 1;i--) result.push_back({0, i});

    ll cy = 0, cx = 1;
    while(m--){
        ll op; cin >> op;
        if(op == 1){
            char c; cin >> c;
            if(c == 'L') cx--;
            if(c == 'R') cx++;
            if(c == 'U') cy++;
            if(c == 'D') cy--;
            result.push_back({cy, cx});
        }
        else{
            ll v; cin >> v;
            ll sz = result.size();
            auto[ry, rx] = result[sz - v];
            cout << rx << " " << ry << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

