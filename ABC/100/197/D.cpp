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

long double dist(ll x1, ll y1, ll x2, ll y2){
    ll dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}


int main() {
    fastio;

    cin >> n;
    ll x1, x2, y1, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    long double mx = (x1 + x2) / (long double)2, my = (y1 + y2) / (long double)2;
    long double len = dist(x1, y1, x2, y2) / (long double)2;
    long double vpx = (x1 - mx) / len, vpy = (y1 - my) / len;
    long double angle = 2 * M_PI / n;
    
    long double ny, nx;
    nx = cos(angle) * vpx - sin(angle) * vpy;
    ny = sin(angle) * vpx + cos(angle) * vpy;

    cout.precision(10);
    cout << mx + nx * len << " " << my + ny * len;
    

    return 0;
}
