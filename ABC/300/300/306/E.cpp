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
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
ll arr[MAX]; bool in[MAX];
set <pll> hi, low;


int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) hi.insert({0, i}), in[i] = 1;
    for(int i = m + 1;i <= n;i++) low.insert({0, i});

    ll result = 0;
    if(n == m){
        while(k--){
            ll idx, v; cin >> idx >> v;
            result += v - arr[idx];
            arr[idx] = v;

            cout << result << "\n";
        }

        return 0;
    }

    while(k--){
        ll idx, v; cin >> idx >> v;
        if(in[idx]) {
            hi.erase({arr[idx], idx}); 
            pll le = *--low.end();

            if(v > le.x){
                result += v - arr[idx];
                hi.insert({v, idx});
            }
            else{
                result += le.x - arr[idx];
                low.erase(--low.end());
                hi.insert(le);
                low.insert({v, idx});
                in[le.y] = 1; in[idx] = 0;
            }
        }
        else {
            low.erase({arr[idx], idx});
            pll hb = *hi.begin();

            if(v > hb.x){
                result += v - hb.x;
                hi.erase(hi.begin());
                hi.insert({v, idx});
                low.insert(hb);
                in[hb.y] = 0; in[idx] = 1;
            }
            else{
                low.insert({v, idx});
            }
        }
        arr[idx] = v;

        cout << result << "\n";
    }


    return 0;
}
