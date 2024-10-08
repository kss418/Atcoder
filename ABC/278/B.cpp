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

    ll h; cin >> h >> m; m--;
    while(1){
        m++; if(m == 60) m = 0, h++;
        if(h == 24) h = 0;

        ll a = h / 10, b = h % 10;
        ll c = m / 10, d = m % 10;
        
        swap(b, c);
        ll nh = a * 10 + b, nm = c * 10 + d;
        if(nh >= 24 || nm >= 60) continue;

        cout << h << " " << m; break;
    }


    return 0;
}
