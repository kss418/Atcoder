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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX][MAX];
ll dp[MAX][MAX], sz[MAX];

bool match(ll idx, string cur){
    ll sz = cur.size();
    if(idx < sz) return 0;
    string now = s.substr(idx - sz, sz);
    return cur == now;
}

int main() {
    fastio;

    cin >> s >> n;
    for(int i = 1;i <= n;i++){
        cin >> sz[i];
        for(int j = 1;j <= sz[i];j++) cin >> st[i][j];
    }

    memset(dp, 0x3f, sizeof(dp)); dp[0][0] = 0;
    for(int i = 1;i <= n;i++){
        dp[i][0] = dp[i - 1][0];
        for(int j = 1;j <= s.size();j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            for(int k = 1;k <= sz[i];k++){
                string cur = st[i][k]; ll sz = cur.size();
                if(match(j, cur)) dp[i][j] = min(dp[i][j], dp[i - 1][j - sz] + 1);
            }
        }
    }

    ll ret = dp[n][s.size()];
    cout << (ret == INF ? -1 : ret);

     
    return 0;
}
