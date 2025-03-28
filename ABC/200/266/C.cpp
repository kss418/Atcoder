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
pll a[4];

class _ccw{
public:
    _ccw() {}

    ll ret(pll v1, pll v2, pll v3){
        ll num = v1.x * v2.y + v2.x * v3.y + v3.x * v1.y;
        num -= v1.y * v2.x + v2.y * v3.x + v3.y * v1.x;

        if(num > 0) return 1;
        else if(num < 0) return -1;
        return 0;
    }
};


int main() {
    fastio;

    for(int i = 0;i < 4;i++) cin >> a[i].x >> a[i].y;
    _ccw ccw; ll flag = 1;

    for(int i = 0;i < 4;i++){
        if(ccw.ret(a[i], a[(i + 1) % 4], a[(i + 2) % 4]) < 0) flag = 0;
    }

    if(flag) cout << "Yes";
    else cout << "No";


    return 0;
}
