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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll sq = 501;
ll a[MAX], dp[MAX];
ll num[sq][sq];

void run(){
    cin >> n; dp[1] = 1; 
    for(int i = 1;i <= n;i++) cin >> a[i];
    
    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < sq;j++){
            dp[i] += num[j][i % j];
            dp[i] %= MOD;
        }

        if(a[i] < sq){
            num[a[i]][i % a[i]] += dp[i];
            num[a[i]][i % a[i]] %= MOD;
        }
        else{
            for(int j = a[i] + i;j <= n;j += a[i]){
                dp[j] += dp[i]; dp[j] %= MOD;
            }
        }
        
        result += dp[i] % MOD;
        result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

