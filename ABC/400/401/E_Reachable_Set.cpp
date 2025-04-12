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
ll a[MAX], result[MAX];
vector <ll> adj[MAX];
priority_queue <ll> pq;

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

void run(){
    cin >> n >> m; 
    ll cnt = n; _uf uf(n + 1);
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i = n;i >= 2;i--){
        ll now = INF;
        for(auto& nxt : adj[i]) now = min(now, nxt);
        pq.push(now);
        while(!pq.empty() && pq.top() >= i) pq.pop();

        result[i - 1] = pq.size();
    }

    ll idx = 1;
    for(int i = 2;i <= n;i++){
        ll mx = i;
        for(auto& nxt : adj[i]){
            if(nxt >= i) continue;
            uf.merge(i, nxt);
            if(!uf.same(1, nxt)) continue;
        }

        while(idx <= n && uf.same(1, idx)) idx++;
        if(idx - 1!= i) result[i] = -1;
    }

    for(int i = 1;i <= n;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

