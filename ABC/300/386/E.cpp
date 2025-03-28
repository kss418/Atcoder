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
ll a[MAX], result, now, all;
vector <ll> num;

bool chk(ll flag){
    if(!flag && num.size() == m) return 1;
    else if(flag && num.size() == n - m) return 1;
    return 0;
}

void bt(ll flag){
    if(chk(flag)){
        if(!flag) result = max(now, result);
        else result = max(all ^ now, result);
        return;
    }

    for(int i = num.empty() ? 1 : num.back() + 1;i <= n;i++){
        num.push_back(i); now ^= a[i];
        bt(flag);
        num.pop_back(); now ^= a[i];
    }
}

int main() {
    fastio;

    cin >> n >> m; 
    for(int i = 1;i <= n;i++) cin >> a[i], all ^= a[i];

    bt(m >= n - m); cout << result;

     
    return 0;
}
