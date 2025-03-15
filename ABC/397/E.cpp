#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
ll dp[MAX], result = 1, cnt;
vector <ll> adj[MAX];

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 1;

    vector <ll> arr;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        arr.push_back(solve(nxt, cur));
    }
    sort(all(arr), greater<ll>());

    ll sum = 0, cnt = 0;
    for(auto& i : arr){
        if(i == m) continue;
        if(i < m) sum += i, cnt++;
    }

    if(cnt > 2) result = 0;
    if(cnt == 2 && sum != m - 1) result = 0;

    return ret = sum + 1;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i < n * m;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    solve(1);
    for(int i = 1;i <= n * m;i++){
        if(solve(i) != m) continue;
        cnt++;
    }

    if(cnt != n) result = 0;
    cout << (result ? "Yes" : "No");
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

