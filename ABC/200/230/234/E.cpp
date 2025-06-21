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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
set <ll> num;
map <pll, bool> dp;

void dfs(ll cur, ll d, ll cnt, ll la){
    if(cur > 1e18) return;
    if(la < 0 || la >= 10) return;
    if(cur < 0) return;
    if(dp.count({cur, d})) return;
    num.insert(cur); dp[{cur, d}] = 1;

    cnt *= 10;
    dfs(cur + (la + d) * cnt, d, cnt, la + d);
}


int main() {
    fastio;

    cin >> n;

    for(int i = 0;i <= 9;i++){
        for(int d = 0;d <= 9;d++){
            dfs(i, d, 1, i);
            dfs(i, -d, 1, i);
        }
    }

    cout << *num.lower_bound(n);


    return 0;
}
