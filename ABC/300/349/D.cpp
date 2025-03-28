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
vector <pll> result;

void solve(ll l, ll r){
    if(l == r) return;
    ll nxt = 0;
    for(ll i = 0;i <= 60;i++){
        ll num = 1ll << i;
        if(l + num > r) break;
        if(l % num == 0) nxt = i;
    }

    result.push_back({l, l + (1ll << nxt)});
    solve(l + (1ll << nxt), r);
}

int main() {
    fastio;
    
    ll l, r; cin >> l >> r;
    ll cur = l;

    solve(l, r); cout << result.size() << "\n";
    for(auto& i : result) cout << i.x << " " << i.y << "\n";
     
     
    return 0;
}
