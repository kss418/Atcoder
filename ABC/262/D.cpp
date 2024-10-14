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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX][MAX], num;

ll solve(ll cur, ll cnt, ll mod){
    ll& ret = dp[cur][cnt][mod];
    if(ret != -1) return ret;
    if(!cnt && !mod) return ret = 1;
    if(!cnt && mod) return ret = 0;
    if(!cur) return ret = 0;

    ret = 0;
    ret += solve(cur - 1, cnt, mod); ret %= MOD;
    ret += solve(cur - 1, cnt - 1, ((mod - a[cur]) % num + num) % num);

    return ret %= MOD;
}

int main() {
    fastio;

    cin >> n; 
    for (int i = 1;i <= n;i++) cin >> a[i];

    ll result = 0;
    for(int i = 1;i <= n;i++){
        memset(dp, -1, sizeof(dp)); num = i;
        result += solve(n, i, 0);
        result %= MOD;
    }

    cout << result;
    
    
    return 0;
}
