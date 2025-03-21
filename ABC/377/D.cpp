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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
pll a[MAX];
ll mx[MAX];

int main() {
    fastio;

    cin >> n >> m; ll result = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + n + 1);
    fill(mx + 1, mx + m + 2, m);
 
    for(int i = 1;i <= n;i++){
        mx[a[i].x] = min(mx[a[i].x], a[i].y - 1);
    }

    for(int i = m;i >= 1;i--){
        mx[i] = min(mx[i], mx[i + 1]);
        result += mx[i] - i + 1;
    }

    cout << result;


    return 0;
}
