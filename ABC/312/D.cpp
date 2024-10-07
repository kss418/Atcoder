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
constexpr ll MAX = 3010;
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][2];

ll solve(ll cur, ll cnt, ll num){
    if(cnt < 0) return 0;
    ll& ret = dp[cur][cnt][num];
    if(ret != -1) return ret; ret = 0;

    if(cur == s.size() - 1 && !cnt) return ret = 1;
    else if (cur == s.size() - 1) return ret = 0;

    if(s[cur] == '(' && num == -1) return ret = 0;
    else if(s[cur] == ')' && num == 1) return ret = 0;

    ret += solve(cur + 1, cnt + 1, 1) % MOD;
    ret += solve(cur + 1, cnt - 1, -1) % MOD;
    ret %= MOD; 
    
    return ret;
}


int main() {
    fastio;

    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1, 1);


    return 0;
}
