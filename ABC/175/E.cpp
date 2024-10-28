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
constexpr ll MAX = 3010;
constexpr ll MOD = 998244353;
ll dp[MAX][MAX][4], arr[MAX][MAX];

ll solve(ll cy, ll cx, ll cnt){
    ll&ret = dp[cy][cx][cnt];
    if(cy == 0 || cx == 0) return ret = 0;
    if(ret != -1) return ret;
    ret = 0;

    if(!cnt) for(int i = 0;i < 4;i++) ret = max(solve(cy - 1, cx, i), ret);
    if(cnt) ret = max(solve(cy, cx - 1, cnt - 1) + arr[cy][cx], ret);
    if(cnt == 1) for(int i = 0;i < 4;i++) ret = max(solve(cy - 1, cx, i) + arr[cy][cx], ret);
    ret = max(solve(cy, cx - 1, cnt), ret);

    return ret;
}

int main() {
    fastio;


    cin >> n >> m >> k;
    while(k--){
        ll y, x, co; cin >> y >> x >> co;
        arr[y][x] = co;
    }

    memset(dp, -1, sizeof(dp)); dp[1][1][0] = 0;
    ll result = 0;
    for(int i = 0;i < 4;i++) result = max(result, solve(n, m, i));

    cout << result;


    return 0;
}

