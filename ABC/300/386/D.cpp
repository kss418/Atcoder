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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
map <ll, pll> ay, ax;

int main() {
    fastio;

    cin >> n >> m; ll result = 1;
    while(m--){
        ll cy, cx; char c; cin >> cy >> cx >> c;
        if(!ay.count(cy)) ay[cy] = {0, INF};
        if(!ax.count(cx)) ax[cx] = {0, INF};

        if(c == 'B'){
            ay[cy].x = max(ay[cy].x, cx);
            ax[cx].x = max(ax[cx].x, cy);
        }
        else{
            ay[cy].y = min(ay[cy].y, cx);
            ax[cx].y = min(ax[cx].y, cy);
        }
    }
    
    ll pre = INF;
    for(auto& i : ay){
        auto[idx, now] = i;
        auto[mn, mx] = now;
        if(mn > pre) result = 0;
        pre = mx - 1;
        if(mn < mx) continue;
        result = 0;
    }

    pre = INF;
    for(auto& i : ax){
        auto[idx, now] = i;
        auto[mn, mx] = now;
        if(mn > pre) result = 0;
        pre = mx - 1;
        if(mn < mx) continue;
        result = 0;
    }

    if(result) cout << "Yes";
    else cout << "No";

     
    return 0;
}
