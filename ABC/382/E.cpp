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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ld dp[MAX], a[MAX], num[MAX][MAX];


ld cal(ll cur, ll cnt){
    ld& ret = num[cur][cnt];
    if(cnt < 0) return 0;
    if(ret > -0.5) return ret;
    if(!cur) return ret = 0;

    ret = cal(cur - 1, cnt - 1) * a[cur] / (ld)100;
    ret += cal(cur - 1, cnt) * (100 - a[cur]) / (ld)100;

    return ret;
}

ld solve(ll cur){
    ld& ret = dp[cur];
    if(ret > -0.5) return ret;
    ret = 1;

    for(int i = 1;i <= n;i++){
        ret += solve(max(cur - i, 0ll)) * cal(n, i); 
    }
    ret /= 1 - cal(n, 0);

    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < MAX;i++){
        dp[i] = -1;
        for(int j = 0;j < MAX;j++) num[i][j] = -1;
    }
    num[0][0] = 1; dp[0] = 0;
    
    cout.precision(20);
    cout << solve(m);
  
     
    return 0;
}
