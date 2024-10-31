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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51;
constexpr ll MOD = 998244353;
ll a[MAX][MAX];


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }
    
    ll flag = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            for(int cy = i + 1;cy <= n;cy++){
                for(int cx = j + 1;cx <= m;cx++){
                    if(a[i][j] + a[cy][cx] > a[cy][j] + a[i][cx]) flag = 0;
                }
            }
        }
    }

    if(flag) cout << "Yes";
    else cout << "No";
    
    
    return 0;
}
