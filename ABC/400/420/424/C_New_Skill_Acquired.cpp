#include <bits/stdc++.h>
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
deque <ll> q;
vector <ll> adj[MAX];
bool v[MAX];

void run(){
    cin >> n; q.push_back(0);
    for(int i = 1;i <= n;i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(i);
        adj[b].push_back(i);
    }

    ll result = 0;
    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        if(v[cur]) continue; 
        v[cur] = 1; result++;

        for(auto& nxt : adj[cur]){
            if(v[nxt]) continue;
            q.push_back(nxt);
        }
    }

    cout << result - 1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}