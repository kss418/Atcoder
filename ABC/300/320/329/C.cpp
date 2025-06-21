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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll mx[26];

void run(){
    cin >> n >> s; ll cnt = 0;
    for(int i = 0;i < s.size();i++){
        if(!i || s[i] == s[i - 1]) cnt++;
        else {
            mx[s[i - 1] - 'a'] = max(mx[s[i - 1] - 'a'], cnt);
            cnt = 1;
        }
    }
    mx[s.back() - 'a'] = max(mx[s.back() - 'a'], cnt);

    ll result = 0;
    for(int i = 0;i < 26;i++) result += mx[i];
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

