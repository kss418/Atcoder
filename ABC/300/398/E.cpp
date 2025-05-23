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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll arr[MAX][MAX];
ll a[MAX], cnt;
set <ll> num[MAX];

void dfs(ll cur, ll num, ll pre = -1){
    if(a[cur] != -1) return;
    a[cur] = num; 
    for(auto& nxt : adj[cur]) dfs(nxt, num ^ 1, cur);
}

void output(){
    for(int i = 1;i <= n;i++){
        if(num[i].empty()) continue;
        cout << i << " " << *num[i].begin() << endl;
        num[i].erase(num[i].begin()); cnt--;
        return;
    }
}

void input(){
    ll s, e; cin >> s >> e;
    if(s == -1) return;
    if(s > e) swap(s, e); cnt--;
    num[s].erase(num[s].find(e));
}

void run(){
    cin >> n; memset(a, -1, sizeof(a));
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
        arr[s][e] = arr[e][s] = 1;
    }

    dfs(1, 0);
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(a[i] == a[j]) continue;
            if(arr[i][j]) continue;
            cnt++; num[i].insert(j);
        }
    }

    if(cnt & 1){
        cout << "First" << endl;
        while(cnt){
            output();
            input();
        }
    }
    else{
        cout << "Second" << endl;
        while(cnt){
            input();
            output();
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

