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
ll a[MAX], num;

ll dnc(ll l, ll r){
    if(l == r) return s[l] - '0';
    ll sz = (r - l + 1) / 3;
    ll fi = dnc(l, l + sz - 1), se = dnc(l + sz, l + 2 * sz - 1), th = dnc(l + 2 * sz, r);
    ll c0 = 0, c1 = 0;
    if(fi) c1++; else c0++; if(se) c1++; else c0++; if(th) c1++; else c0++;
    if(c1 > c0) return 1; return 0;
}

ll solve(ll l, ll r){
    if(l == r) return (num != s[l] - '0');
    ll sz = (r - l + 1) / 3;
    ll fi = solve(l, l + sz - 1), se = solve(l + sz, l + 2 * sz - 1), th = solve(l + 2 * sz, r);
    ll mx = max({fi, se, th});

    return fi + se + th - mx;
}

void run(){
    cin >> n >> s;
    num = dnc(0, s.size() - 1) ^ 1;
    cout << solve(0, s.size() - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

