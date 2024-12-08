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
constexpr ll MAX = 501; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p[MAX], u[MAX], c[MAX];
ll dp[MAX][50101];
vector <ll> idx[MAX];

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        cin >> p[i] >> u[i] >> c[i];
        idx[c[i]].push_back(i);
    }

    for(int i = 1;i <= n;i++){
        for(auto& cur : idx[i]){
            for(int j = m;j >= p[cur];j--){
                dp[i][j] = max(dp[i][j], dp[i][j - p[cur]] + u[cur]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - p[cur]] + u[cur] + k);
            }
        }
        
        for(int j = 0;j <= m;j++) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++) result = max(result, dp[i][j]);
    }

    cout << result;
    
     
    return 0;
}
