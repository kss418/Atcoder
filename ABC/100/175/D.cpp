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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 5010;
constexpr ll MOD = 998244353;
ll p[MAX], c[MAX];
bool v[MAX];

int main() {
    fastio;

    cin >> n >> m; 
    for(int i = 1;i <= n;i++) cin >> p[i];
    for(int i = 1;i <= n;i++) cin >> c[i];
    
    ll result = -INF;
    for(int i = 1;i <= n;i++){
        memset(v, 0, sizeof(v));
        vector <ll> cycle;
        ll cur = i, all = 0;
        while(!v[cur]){
            v[cur] = 1; all += c[cur];
            cycle.push_back(cur);
            cur = p[cur];
        }

        ll size = cycle.size(), sum = 0;

        for(int i = 0;i < size;i++){
            sum += c[cycle[i]];
            if(i >= m) break;

            ll cnt = (m - i - 1) / size;
            ll mx = sum + max(0ll, all) * cnt;
            result = max(result, mx);
        }   
    }

    cout << result;


    return 0;
}

