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
ll a[5][MAX], sz[5];
set <ll> num;

int main() {
    fastio;

    for(int i = 1;i <= 4;i++){
        cin >> sz[i];
        for(int j = 1;j <= sz[i];j++) cin >> a[i][j];
    }
    
    for(int i = 1;i <= sz[1];i++){
        for(int j = 1;j <= sz[2];j++){
            for(int k = 1;k <= sz[3];k++){
                num.insert(a[1][i] + a[2][j] + a[3][k]);
            }
        }
    }

    for(int i = 1;i <= sz[4];i++){
        if(num.count(a[4][i])) cout << "Yes\n";
        else cout << "No\n";
    }

     
    return 0;
}
