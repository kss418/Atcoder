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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX][MAX];

int main() {
    fastio;

    ll d; cin >> n >> k >> d;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= k;j++){
            for(int k = 0;k < d;k++) dp[i][j][k] = -INF;
        }
    }
    dp[0][0][0] = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= k;j++){
            for(int l = 0;l < d;l++){
                dp[i][j][l] = max(dp[i - 1][j][l], dp[i][j][l]);
                if(!j) continue;
                dp[i][j][l] = max(dp[i - 1][j - 1][((l - a[i]) % d + d) % d] + a[i], dp[i][j][l]);
            }
        }
    }

    ll ret = dp[n][k][0];
    if(ret < 0) cout << -1;
    else cout << ret; 


    return 0;
}
