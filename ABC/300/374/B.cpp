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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;

int main() {
    fastio;

    string t; cin >> s >> t;
    ll result = 0;
    for(int i = 1;i <= min(s.size(), t.size());i++){
        if(s[i - 1] != t[i - 1]) {
            result = i; break;
        }
    }
    if(!result && s.size() != t.size()) result = min(s.size(), t.size()) + 1;
    
    cout << result;


    return 0;
}
