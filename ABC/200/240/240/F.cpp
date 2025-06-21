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
ll x[MAX], y[MAX];


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++) cin >> x[i] >> y[i];
        
        ll cd = 0, nd = 0, result = x[1], cur = 0;
        x[n + 1] = y[n + 1] = 0;
        for(int i = 1;i <= n;i++){
            cd = nd; nd = cd + x[i] * y[i]; cd += x[i];
            cur += (cd + nd) * y[i] / 2;
            result = max(result, cur);

            if(x[i + 1] >= 0 || nd < 0) continue;
            ll nxt = x[i + 1], ncd = nd + nxt;
            ll mv = min(y[i + 1], nd / -nxt);
            ll nnd = nd + nxt *  mv; 

            result = max(result, cur + ((ncd + nnd) * mv / 2));
        }
        result = max(result, cur);


        cout << result << "\n";
    }
    

    return 0;
}
