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
constexpr ll MAX = 4; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <vector<ll>> a;
map <vector <vector<ll>>, ll> dp;

bool chk(vector<vector<ll>>& a){
    for(int i = 0;i < 3;i++){
        if(a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0]) return 1;
        if(a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i]) return 1;
    }
    
    if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0]) return 1;
    if(a[2][0] == a[1][1] && a[1][1] == a[0][2] && a[1][1]) return 1;

    return 0;
}

ll solve(vector<vector<ll>> now, ll t){
    if(dp.count(now)) return dp[now];
    ll& ret = dp[now];
    ret = (t) ? INF : -INF;
    if(chk(now)) return ret = (t) ? 1e12 : -1e12;

    ll num = (t) ? -1 : 1;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(now[i][j]) continue;
            now[i][j] = num;
            if(t == 0) ret = max(ret, solve(now, t ^ 1) + a[i][j]);
            else ret = min(ret, solve(now, t ^ 1) - a[i][j]);
            now[i][j] = 0;
        }
    }

    if(ret == -INF || ret == INF) ret = 0;
    return ret;
}

int main() {
    fastio;
    
    a.resize(3, vector<ll>(3, 0));
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++) cin >> a[i][j];
    }

    vector <vector <ll>> s(3, vector<ll>(3, 0));
    ll ret = solve(s, 0);

    if(ret > 0) cout << "Takahashi";
    else cout << "Aoki";
    
     
    return 0;
}
