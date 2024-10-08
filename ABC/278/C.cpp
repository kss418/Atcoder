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
map <ll, set<ll>> num;

int main() {
    fastio;

    ll q; cin >> n >> q;
    while(q--){
        ll a, b; cin >> t >> a >> b;
        if(t == 1) num[a].insert(b);
        else if(t == 2) num[a].erase(b);
        else {
            bool flag = (bool)num[a].count(b) & (bool)num[b].count(a);
            if(flag) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    

    return 0;
}
