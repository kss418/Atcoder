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
constexpr ll MAX = 12; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll result;

ll dist(pll a, pll b){
    ll dx = abs(a.x - b.x);
    ll dy = abs(a.y - b.y);
    return dx + dy;
}

void chk(ll y1,ll x1,ll y2, ll x2){
    ll ret = 0; pll a = {y1, x1}, b = {y2, x2};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            pll cur = {i, j};
            if(st[i][j] == '#') continue;
            if(dist(cur, a) > k && dist(cur, b) > k) continue;
            ret++;
        }
    }

    result = max(result, ret);
}

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            for(int k = 0;k < n;k++){
                for(int l = 0;l < m;l++){
                    if(i == k && j == l) continue;
                    if(st[i][j] == '#' || st[k][l] == '#') continue;
                    chk(i, j, k, l);
                }
            }
        }
    }

    cout << result;

     
    return 0;
}
