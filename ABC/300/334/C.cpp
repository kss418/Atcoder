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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], pre[MAX], suf[MAX], diff[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 1;i < m;i++) diff[i] = a[i + 1] - a[i];

    for(int i = 1;i < m;i+=2) pre[i] = pre[max<ll>(i - 2, 0ll)] + diff[i];
    for(int i = 2;i < m;i+=2) pre[i] = pre[max<ll>(i - 2, 0ll)] + diff[i];
    for(int i = m - 1;i >= 1;i-=2) suf[i] = suf[i + 2] + diff[i];
    for(int i = m - 2;i >= 1;i-=2) suf[i] = suf[i + 2] + diff[i];

    ll result = INF;
    if(m % 2 == 0) result = pre[m - 1];
    else for(int i = 1;i <= m;i+=2) {
        result = min(result, pre[max<ll>(i - 2, 0ll)] + suf[i + 1]);
    }

    cout << (result == INF ? 0 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

