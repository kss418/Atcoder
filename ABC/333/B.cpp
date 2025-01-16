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
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

void run(){
    string a, b; cin >> a >> b;
    if(a[0] > a[1]) swap(a[0], a[1]);
    if(b[0] > b[1]) swap(b[0], b[1]);

    if(a[1] - a[0] == b[1] - b[0] || (5 + a[0] - a[1]) == b[1] - b[0] || (a[1] - a[0]) == 5 + b[0] - b[1]) cout << "Yes";
    else cout << "No";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}