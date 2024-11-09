#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];

ll sum(ll a, ll b){
    ll ret = a * (a + 1) / 2;
    ret -= (a - b) * (a - b + 1) / 2;

    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> a[i].x;
    for(int i = 1;i <= m;i++) cin >> a[i].y;
    sort(a + 1, a + m + 1);

    ll result = 0, mx = n + 1, s = 0;
    for(int i = m;i >= 1;i--){
        s += a[i].y;
        if(mx <= a[i].x) continue;
        ll diff = mx - a[i].x - 1;
        result += sum(diff, min(diff + 1, a[i].y));

        mx = max(a[i].x, mx - a[i].y);
    }

    if(mx != 1 || s != n) cout << -1;
    else cout << result;


    return 0;
}

