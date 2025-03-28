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
ll a[MAX], result;
map <ll, set<ll>> sx, sy;

ll lbx(ll cy, ll cx, ll v){
    ll mx = cx + v, mn = cx, ret = 0;
    if(mx < mn) swap(mx, mn);

    while(1){
        if(sx[cy].lower_bound(mn) == sx[cy].upper_bound(mx)) break;
        ll now = *sx[cy].lower_bound(mn);
        sx[cy].erase(sx[cy].lower_bound(mn));
        sy[now].erase(sy[now].lower_bound(cy));
        ret++;
    }

    return ret;
}

ll lby(ll cy, ll cx, ll v){
    ll mx = cy + v, mn = cy, ret = 0;
    if(mx < mn) swap(mx, mn);

    while(1){
        if(sy[cx].lower_bound(mn) == sy[cx].upper_bound(mx)) break;
        ll now = *sy[cx].lower_bound(mn);
        sy[cx].erase(sy[cx].lower_bound(mn));
        sx[now].erase(sx[now].lower_bound(cx));
        ret++;
    }

    return ret;
}

int main() {
    fastio;

    ll cy, cx; cin >> n >> m >> cx >> cy;
    for(int i = 1;i <= n;i++){
        ll y, x; cin >> x >> y;
        sx[y].insert(x);
        sy[x].insert(y);
    }

    while(m--){
        char c; ll v; cin >> c >> v;
        if(c == 'L'){
            result += lbx(cy, cx, -v);
            cx -= v;
        }
        else if(c == 'R'){
            result += lbx(cy, cx, v);
            cx += v;
        }
        else if(c == 'U'){
            result += lby(cy, cx, v);
            cy += v;
        }
        else{
            result += lby(cy, cx, -v);
            cy -= v;
        }
    }

    cout << cx << " " << cy << " " << result;

     
    return 0;
}
