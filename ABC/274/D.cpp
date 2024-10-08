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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
constexpr ll MID = 10000;
ll a[MAX];
bool dp[MAX][20101];


int main() {
    fastio;

    ll x, y; cin >> n >> x >> y;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dp[1][a[1] + MID] = 1; dp[0][MID] = 1;

    for(int i = 2;i <= n;i++){
        for(int j = 0;j <= 20000;j++){
            if(j - a[i] >= 0 && j - a[i] <= 20000){
                dp[i][j] = max(dp[i][j], dp[i - 2][j - a[i]]);
            }

            if(j + a[i] >= 0 && j + a[i] <= 20000){
                dp[i][j] = max(dp[i][j], dp[i - 2][j + a[i]]);
            }
        }
    }

    ll cx, cy;
    if(n % 2) cx = n, cy = n - 1;
    else cx = n - 1, cy = n;

    if(dp[cx][x + MID] && dp[cy][y + MID]) cout << "Yes";
    else cout << "No";

 
    return 0;
}
