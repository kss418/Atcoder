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
ll n, m, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 21;
constexpr ll MOD = 998244353;
ll k[MAX];


int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < n;i++) cin >> k[i];
    
    ll result = INF;
    for(int i = 0;i < (1ll << n);i++){
        ll a = 0, b = 0;
        for(int j = 0;j < n;j++){
            if(i & (1ll << j)) a += k[j];
            else b += k[j];
        }

        result = min(result, max(a, b));
    }
    
    cout << result;


    return 0;
}