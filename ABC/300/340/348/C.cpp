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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
map <ll, ll> mn;

int main() {
    fastio;

    cin >> n; 
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        if(!mn.count(a[i].y)) mn[a[i].y] = a[i].x;
        else mn[a[i].y] = min(mn[a[i].y], a[i].x);
    }

    ll result = 0;
    for(auto& i : mn) result = max(result, i.y);
    
    cout << result;


    return 0;
}
