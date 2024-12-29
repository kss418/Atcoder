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
constexpr ll MAX = 13; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cnt[MAX], use[4];

int main() {
    fastio;

    for(int i = 1;i <= 4;i++) cin >> n, cnt[n]++;
    for(int i = 1;i <= 13;i++){
        use[cnt[i]]++;
    }

    ll result = 0;
    if(use[1] && use[3]) result = 1;
    else if(use[2] == 2) result = 1;

    if(result) cout << "Yes";
    else cout << "No";

     
    return 0;
}