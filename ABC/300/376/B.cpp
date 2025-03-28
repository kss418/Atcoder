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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX];

int main() {
    fastio;

    cin >> n >> m;
    ll l = 1, r = 2, result = 0;
    while(m--){
        char c; ll v; cin >> c >> v;
        if(c == 'L'){
            if(v > r && r > l) result += abs(l + n - v);
            else if (v < r && r < l) result += abs(v + n - l);
            else result += abs(v - l);
            l = v;
        }
        else{
            if(v > l && l > r) result += abs(r + n - v);
            else if(v < l && l < r) result += abs(v + n - r);
            else result += abs(v - r);
            r = v;
        }
    }

    cout << result;
    

    return 0;
}
