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
ll a[MAX], pre[MAX], suf[MAX];
set <ll> num;

int main() {
    fastio;

    cin >> n >> m; ll cycle = 0;
    for(int i = 1;i <= n;i++) cin >> a[i], cycle += a[i];
    for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];

    ll flag = 0; m %= cycle;
    for(int i = n;i >= 1;i--) suf[i] = suf[i + 1] + a[i], num.insert(suf[i]);
    num.insert(0);

    for(int i = 0;i <= n;i++){
        if(pre[i] > m) break;
        ll cur = m - pre[i];
        if(num.count(cur)) flag = 1;
    }

    m += cycle;
    for(int i = 0;i <= n;i++){
        if(pre[i] > m) break;
        ll cur = m - pre[i];
        if(num.count(cur)) flag = 1;
    }

    if(flag) cout << "Yes";
    else cout << "No";

     
    return 0;
}
