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
constexpr ll MAX = 130; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[16][MAX][MAX][MAX][2];

void run(){
    cin >> s; ll result = 0;
    for(int all = 1;all <= 126;all++){
        dp[0][0][0][all][1]  = 1;
        for(int sz = 0;sz < s.size();sz++){
            for(int sum = 0;sum <= all;sum++){
                for(int mod = 0;mod < all;mod++){
                    for(int f = 0;f <= 1;f++){
                        for(int pl = 0;pl <= 9;pl++){
                            ll nxt = sum + pl;
                            if(nxt > all) continue;
                            if(f && s[sz] - '0' < pl) continue;
                            dp[sz + 1][nxt][(mod * 10 + pl) % all][all][f && s[sz] - '0' == pl] += dp[sz][sum][mod][all][f];
                        }
                    }
                }
            }
        }
         
        result += dp[s.size()][all][0][all][0] + dp[s.size()][all][0][all][1];
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

