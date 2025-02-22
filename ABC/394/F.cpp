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
ll result, ind[MAX], dp[MAX];
vector <ll> adj[MAX];

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 1;

    vector <ll> num;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        num.push_back(solve(nxt, cur));
    }
    sort(all(num)); reverse(all(num));

    if(!num.empty()) result = max(result, num[0] + 1);
    if(num.size() >= 4) result = max(result, num[0] + num[1] + num[2] + num[3] + 1);
    if(num.size() >= 3) ret = max(ret, num[0] + num[1] + num[2] + 1);

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
        ind[s]++; ind[e]++;
    }

    solve(1);
    cout << (result >= 5 ? result : -1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

