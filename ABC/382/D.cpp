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
ll cnt; vector <ll> vec;
vector<vector <ll>> result;

void bt(ll num){
    vec.push_back(num);
    if(vec.size() == n){
        result.push_back(vec);
        return;
    }

    for(int i = vec.back() + 10;i <= m - 10 * (n - vec.size() - 1);i++){
        bt(i);
        vec.pop_back();
    }
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= m - 10 * (n - 1);i++) {
        vec.clear(); bt(i);
    }

    cout << result.size() << "\n";
    for(auto& i : result){
        for(auto& j : i) cout << j << " ";
        cout << "\n";
    }
  
     
    return 0;
}
