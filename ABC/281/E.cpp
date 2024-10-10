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
ll a[MAX]; bool in[MAX];
set <pll> hi, low;

int main() {
    fastio;

    cin >> n >> m >> k; 
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll result = 0;
    for(int i = 1;i <= n;i++){
        if(i > m) {
            if(in[i - m]) {
                low.erase({a[i - m], i - m}), result -= a[i - m];

                if(!hi.empty()){
                    pll hb = *hi.begin(); in[hb.y] = 1;
                    hi.erase(hb); low.insert(hb);
                    result += hb.x;
                }
            }
            else hi.erase({a[i - m], i - m});
        }
        
        if(low.size() < k) {
            low.insert({a[i], i}); in[i] = 1;
            result += a[i];
        }
        else {
            pll le = *--low.end();
            if(a[i] < le.x) {
                low.erase(le); hi.insert(le);
                low.insert({a[i], i}); result += a[i] - le.x;
                in[le.y] = 0; in[i] = 1;
            }
            else hi.insert({a[i], i});
        }

        if(i >= m) cout << result << " ";
    }


    return 0;
}
