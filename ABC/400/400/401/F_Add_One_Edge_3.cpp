#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX][2];
ll dp[MAX][2], mx[MAX][2], result;
vector <ll> a[2];
ll dist[2], sum[MAX];

ll solve(ll cur, ll cnt, ll pre = -1){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;

    for(auto& nxt : adj[cur][cnt]){
        if(nxt == pre) continue;
        ret = max(ret, solve(nxt, cnt, cur) + 1);
    }

    return ret;
}

void reroot(ll cur, ll mx, ll cnt, ll pre = -1){
    a[cnt].push_back(max(solve(cur, cnt), mx));
    
    vector <pll> arr;
    for(auto& nxt: adj[cur][cnt]){
        if(pre == nxt) continue;
        arr.push_back({solve(nxt, cnt), nxt});
    }

    dist[cnt] = max(dist[cnt], solve(cur, cnt) + mx);
    if(arr.empty()) return;
    sort(all(arr), greater<pll>());

    for(auto& [co, nxt] : arr){
        if(nxt == arr[0].y){
            if(arr.size() >= 2) reroot(nxt, max(mx, arr[1].x + 1) + 1, cnt, cur);
            else reroot(nxt, mx + 1, cnt, cur);
        }
        else reroot(nxt, max(mx, arr[0].x + 1) + 1, cnt, cur);
    }

    dist[cnt] = max(dist[cnt], mx + arr[0].x);
    if(arr.size() >= 2) dist[cnt] = max(dist[cnt], max(mx, arr[0].x) + arr[1].x);
}

void run(){
    cin >> n;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s][0].push_back(e);
        adj[e][0].push_back(s);   
    }

    cin >> m;
    for(int i = 1;i < m;i++){
        ll s, e; cin >> s >> e;
        adj[s][1].push_back(e);
        adj[e][1].push_back(s);
    }

    memset(dp, -1, sizeof(dp));
    solve(1, 0); solve(1, 1);
    reroot(1, 0, 0); reroot(1, 0, 1);

    a[0].push_back(INF); a[1].push_back(0);
    sort(all(a[0]), greater<ll>()); sort(all(a[1]));
    for(int i = 1;i < a[1].size();i++) sum[i] = sum[i - 1] + a[1][i];

    ll max_dist = max(dist[0], dist[1]), idx = 1;
    for(int i = 1;i < a[0].size();i++){
        while(idx < a[1].size() && a[0][i] + a[1][idx] + 1 < max_dist) idx++;
        result += sum[a[1].size() - 1] - sum[idx - 1] + (a[0][i] + 1) * (a[1].size() - idx);
        result += max_dist * (idx - 1);
    }

    cout << result;
}  

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

