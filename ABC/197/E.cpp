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
pll a[MAX];
ll mx[MAX], mn[MAX];
ll dp[MAX][2];
map <ll, ll> num;

ll solve(ll cur, ll cnt){
    if(!cur) return 0;
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret;
    ret = 0;

    if(!cnt){
        ll a = solve(cur - 1, 0) + abs(mx[cur] - mn[cur - 1]) + abs(mx[cur] - mn[cur]);
        ll b = solve(cur - 1, 1) + abs(mx[cur] - mx[cur - 1]) + abs(mx[cur] - mn[cur]);
        ret = min(a, b);
    }
    else{
        ll a = solve(cur - 1, 0) + abs(mn[cur] - mn[cur - 1]) + abs(mx[cur] - mn[cur]);
        ll b = solve(cur - 1, 1) + abs(mn[cur] - mx[cur - 1]) + abs(mx[cur] - mn[cur]);
        ret = min(a, b);
    }

    return ret;
}

int main() {
    fastio;

    cin >> n;
    fill(mx + 1, mx + n + 1, -INF);
    memset(mn, 0x3f, sizeof(mn));
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].y >> a[i].x;

    sort(a + 1, a + n + 1); ll seq = 1;
    mx[0] = mn[0] = 0;
    for(int i = 1;i <= n;i++){
        if(num.count(a[i].x)) a[i].x = num[a[i].x];
        else num[a[i].x] = seq++, a[i].x = num[a[i].x];
        mn[a[i].x] = min(mn[a[i].x], a[i].y);
        mx[a[i].x] = max(mx[a[i].x], a[i].y);
    }
    mx[seq] = mn[seq] = 0;

    cout << min(solve(seq, 1), solve(seq, 0));
    

    return 0;
}
