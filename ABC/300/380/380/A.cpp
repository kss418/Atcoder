#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cnt[10];


int main() {
    fastio;

    cin >> n; s = to_string(n);
    for(auto& i : s) cnt[i - '0']++;

    ll flag = 1;
    if(cnt[1] != 1) flag = 0;
    if(cnt[2] != 2) flag = 0;
    if(cnt[3] != 3) flag = 0;
    
    if(flag) cout << "Yes";
    else cout << "No";
    

    return 0;
}

