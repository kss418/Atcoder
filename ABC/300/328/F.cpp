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
ll a[MAX];
vector <ll> result;

class _uf { 
public:
    ll n; vector <ll> p, d, dis;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n; dis.resize(n + 1);
        p.resize(n + 1, -1); d.resize(n + 1); 
    }

    pll find(ll num) { 
        if (p[num] == -1) return { num, 0ll };
        auto [pa, diff] = find(p[num]);
        p[num] = pa; d[num] += diff;
        return { p[num], d[num] };
    }

    void merge(ll a, ll b, ll c) {
        auto [pa, da] = find(a);
        auto [pb, db] = find(b);
        if (pa == pb) { dis[pb] |= (db - da - c != 0); return; }
        p[pa] = pb; dis[pb] |= dis[pa];
        d[pa] = db - da - c; 
    }

    pll diff(ll a, ll b){
        auto [pa, da] = find(a);
        auto [pb, db] = find(b);
        if(pa == pb && !dis[pa]) return { 1, db - da };
        else if(pa == pb && dis[pa]) return { 0, -1 };
        else return { 0, 0 };
    }

    bool same(ll a, ll b) { return find(a).x == find(b).x; }
};

void run(){
    cin >> n >> m; _uf uf(n);
    for(int i = 1;i <= m;i++){
        ll a, b, d; cin >> a >> b >> d;
        if(!uf.same(a, b)) uf.merge(a, b, d);
        auto [able, diff] = uf.diff(a, b);
        if(!able || diff != d) continue;
        result.push_back(i);
    }
    
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

