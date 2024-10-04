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

int main() {
    fastio;

    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    if(sx > tx){
        swap(sx, tx);
        swap(sy, ty);
    }
    
    if((sx + sy) % 2 == 0) sx++;
    if((tx + ty) % 2) tx--;
    ll dy = abs(ty - sy);
    tx -= max(dy - 1, 0ll);
    ll dx = max(tx - sx, 0ll);

    cout << (dx + 1) / 2 + dy;

  
    return 0;
}W