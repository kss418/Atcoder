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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
map <pll, ll> a, dp;
map <ll, set<ll>> sx[MAX], sy[MAX];
map <ll, ll> num;
ll result[MAX];

class node{
public:
    ll y, x, v, idx;
    bool operator<(node& ot){
        return v < ot.v;
    }
};
vector <node> query;


ll solve(ll cy, ll cx){
    if(dp.count({cy, cx})) return dp[{cy, cx}];
    ll& ret = dp[{cy, cx}]; ret = 1;
    ll now = a[{cy, cx}];

    auto ly = sy[cx].upper_bound(now);
    if(ly != sy[cx].end()){
        set<ll>& arr = ly->y;
        if(!arr.empty()) ret = max(ret, *--arr.end() + 1);
    }

    auto lx = sx[cy].upper_bound(now);
    if(lx != sx[cy].end()){
        set<ll>& arr = lx->y;
        if(!arr.empty()) ret = max(ret, *--arr.end() + 1);
    }

    sy[cx][now].insert(ret); sx[cy][now].insert(ret);
    return ret;
}

int main() {
    fastio;
    
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++){
        ll x, y, v; cin >> y >> x >> v;
        query.push_back({y, x, v, i});
    }
    sort(all(query));

    ll seq = 0;
    for(auto& i : query){
        auto&[y, x, v, cur] = i;
        if(!num.count(v)) num[v] = ++seq;
        v = num[v]; a[{y, x}] = v; 
    }

    reverse(all(query));
    for(auto& i : query){
        auto&[y, x, v, cur] = i;
        result[cur] = solve(y, x) - 1;
    }

    for(int i = 1;i <= k;i++) cout << result[i] << "\n";

    
    return 0;
}
