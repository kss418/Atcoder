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

ll _sqrt(ll num){
    ll ret = sqrt(num);
    while(ret * ret < num) ret++;
    while(ret * ret > num) ret--;

    return ret;
}


int main() {
    fastio;

    cin >> n;

    ll result = 0;

    for(ll i = 1;i <= n;i++){
        ll p = i;
        for(ll j = 2;j * j <= i;j++){
            if(p < j * j) break;
            while(p % (j * j) == 0) p /= (j * j);
        }
        ll mx = p * n;
        ll sq = _sqrt(mx) / p;

        result += sq;
    }
    
    cout << result;
    

    return 0;
}
