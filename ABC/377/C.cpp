#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
map <pll, bool> use;
ll dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
ll dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    fastio;

    cin >> n >> m;
    ll result = n * n;
    while(m--){
        ll cx, cy; cin >> cy >> cx;
        if(!use.count({cy, cx})) result--;
        use[{cy, cx}] = 1;
        
        for(int i = 0;i < 8;i++){
            ll nx = cx + dx[i], ny = cy + dy[i];
            if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
            if(use.count({ny, nx})) continue;
            use[{ny, nx}] = 1; result--;
        }
    }   

    cout << result;

    return 0;
}
