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
constexpr ll MAX = 5010;
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX], sum[MAX];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret;
    if(cur == 1) return ret = -INF;
    ret = 0;

    if(cnt) ret = solve(cur - 1, cnt - 1);
    else{
        for(int j = 0;j <= cur;j++){
            ret = max(ret, solve(cur - 1, j) + sum[j]);
        }
    }

    return ret;
}


int main() {
    fastio;

    cin >> n; 
    for(int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;

    for(int i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[(i + 1) / 2];
    }

    ll result = 0;
    for(int i = 0;i <= n;i++){
        result = max(result, solve(n, i) + sum[i]);
    }
    
    cout << result;


    return 0;
}
