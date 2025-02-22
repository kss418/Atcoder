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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
vector <ll> adj[MAX][31][2];
bool v[MAX];
ll d[MAX][MAX];

class node{
public:
    ll s, e, d;
};
deque <node> q;

void run(){
    cin >> n; memset(d, 0x3f, sizeof(d));
    for(int i = 0;i < n;i++) q.push_back({i, i, 0});
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < n;j++){
            if(st[i][j] == '-') continue;
            adj[i][st[i][j] - 'a'][0].push_back(j);
            adj[j][st[i][j] - 'a'][1].push_back(i);
            q.push_back({i, j, 1});
        }
    }

    while(!q.empty()){
        auto[s, e, cd] = q.front(); q.pop_front();
        if(cd >= d[s][e]) continue; d[s][e] = cd;
        for(int i = 0;i < 26;i++){
            for(auto& ns : adj[s][i][1]){
                for(auto& ne : adj[e][i][0]) q.push_back({ns, ne, cd + 2});
            }
        }
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) {
            cout << (d[i][j] == INF ? -1 : d[i][j]) << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

