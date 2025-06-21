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
constexpr ll MAX = 18;
constexpr ll MOD = 998244353;
string st[MAX];
ll dp[MAX][1 << MAX];

ll solve(ll cur, ll use){
    ll& ret = dp[cur][use];
    if(ret != -1) return ret;
    
    for(int nxt = 0;nxt < n;nxt++){
        if(use & (1ll << nxt)) continue;
        if(st[cur].back() != st[nxt].front()) continue;
        ret = max(ret, solve(nxt, use | (1ll << nxt)) ^ 1);
    }
    if(ret == -1) ret = 1;

    return ret;
}

int main() {
    fastio;

    cin >> n; 
    for (int i = 0; i < n; i++) cin >> st[i];
    
    memset(dp, -1, sizeof(dp));
    ll ret = 0;
    for(int i = 0;i < n;i++){
        ret = max(ret, solve(i, (1ll << i)));
    }

    if(ret) cout << "First";
    else cout << "Second";


    return 0;
}
