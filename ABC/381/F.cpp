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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[20][1ll << 20], a[MAX], nidx[20][MAX];
ll result;
vector <ll> idx[20];

bool chk(ll num){
    if(num == 0) return 1;
    return num > 0 && (num & (num - 1)) == 0;
}

ll solve(ll cur, ll v, ll cnt){
    ll& ret = dp[cur][v];
    if(ret != -1) return ret; ret = n;
    if(!v) return ret;

    for(ll nxt = 0;nxt < 20;nxt++){
        if(cur == nxt) continue;
        if((v & (1ll << nxt)) == 0) continue;
        ll nv = v & (~(1ll << cur));
        ret = min(ret, solve(nxt, nv, cnt - 2));
    }

    if(chk(v)) {
        ret = idx[cur][2];
        if(ret < n) result = max(result, cnt);
        return ret;
    }  

    for(int i = 1;i <= 2;i++){
        ret = nidx[cur][ret];
        if(ret >= n) return ret = n;
    }

    if(ret < n) result = max(result, cnt);
    return ret;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < 20;i++) idx[i].push_back(-1);
    for(int i = 0;i < n;i++) {
        cin >> a[i]; a[i]--;
        idx[a[i]].push_back(i);
    }

    for(int i = 0;i < 20;i++){
        for(int j = 0;j < idx[i].size() - 1;j++){
            for(int k = idx[i][j];k < idx[i][j + 1];k++){
                nidx[i][k] = idx[i][j + 1];
            }
        }
        
        for(int j = max(idx[i].back(), 0ll);j <= n;j++) nidx[i][j] = n;
    }
    
    memset(dp, -1, sizeof(dp));

    ll cnt = 0, v = 0;
    for(int i = 0;i < 20;i++) {
        if(idx[i].size() >= 3) v |= (1ll << i), cnt += 2;
    }

    for(int i = 0;i < 20;i++) {
        if(!((1ll << i) & v)) continue;
        solve(i, v, cnt);
    }
    cout << result;

     
    return 0;
}
