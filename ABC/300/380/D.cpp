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
ll a[MAX]; ull len[MAX];

char solve(ll cur, ll cnt){
    if(cur <= len[cnt]) return solve(cur, cnt - 1);
    if(cur <= s.size()) return s[cur - 1];
    return solve(cur - len[cnt], cnt - 1) ^ 32;
}

int main() {
    fastio;

    cin >> s >> t; 
    ll mx = 0; len[1] = s.size();

    for(int i = 2;i <= 62;i++){
        len[i] = len[i - 1] * 2;
        if(len[i] > 1e18) break;
        mx = i;
    }   

    while(t--){
        cin >> n;
        cout << solve(n, mx) << " ";
    }


    return 0;
}

