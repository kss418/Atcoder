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
vector <ll> num[26];
ll tf[26];

int main() {
    fastio;

    cin >> n >> s >> m;
    for(int i = 0;i < 26;i++) num[i].push_back(i);
    while(m--){
        char l, r; cin >> l >> r;
        if(l == r) continue;
        for(auto& i : num[l - 'a']) num[r - 'a'].push_back(i);
        num[l - 'a'].clear();
    }

    for(int i = 0;i < 26;i++){
        for(auto& j : num[i]) tf[j] = i;
    }

    for(auto& i : s) cout << (char)(tf[i - 'a'] + 'a');

     
    return 0;
}
