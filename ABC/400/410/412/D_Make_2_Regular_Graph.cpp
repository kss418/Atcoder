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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll ind[MAX], adj[MAX][MAX], result = INF, cnt;
vector <pll> arr;

void up(ll idx){
    ind[idx]++;
    if(ind[idx] == 3) cnt++;
    if(ind[idx] == 2) cnt--;
}

void dn(ll idx){
    ind[idx]--;
    if(ind[idx] == 2) cnt--;
    if(ind[idx] == 1) cnt++;
}

void bt(){
    if(!cnt){
        result = min<ll>(result, arr.size());
        return;
    }


    ll cx = arr.empty() ? 1 : arr.back().x;
    for(int i = 1;i < cx;i++){
        if(ind[i] != 2) return;
    }

    for(int i = cx;i <= n;i++){
        ll cy = (i == cx && !arr.empty()) ? arr.back().y + 1 : i + 1;
        for(int j = cy;j <= n;j++){
            if(adj[i][j]){
                adj[i][j] = 0;
                dn(i); dn(j);
                arr.push_back({i, j});

                bt();
                
                arr.pop_back();
                up(i); up(j);
                adj[i][j] = 1;
            }
            else{
                adj[i][j] = 1;
                up(i); up(j);
                arr.push_back({i, j});
                
                bt();

                arr.pop_back();
                dn(i); dn(j);
                adj[i][j] = 0;
            }
        }
    }
}

void run(){
    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        ll mn = min(s, e), mx = max(s, e);
        adj[mn][mx] = 1;
        ind[s]++; ind[e]++;
    }

    for(int i = 1;i <= n;i++){
        if(ind[i] != 2) cnt++;
    }
    
    bt();
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

