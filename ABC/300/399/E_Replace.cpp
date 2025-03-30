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
ll result;
vector <ll> tf, ind;

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
    string a, b; cin >> n >> a >> b;
    if(a == b){ cout << 0; return; }
    
    bool flag = 1; tf.resize(26, -1);
    for(int i = 0;i < n;i++){
        if(tf[a[i] - 'a'] != -1){
            if(tf[a[i] - 'a'] != b[i] - 'a') flag = 0;
        }
        else tf[a[i] - 'a'] = b[i] - 'a';
    }

    vector <ll> tmp = tf;
    sort(all(tmp));
    bool perm = 1;
    for(int i = 0;i < 26;i++){
        perm &= (tmp[i] == i);
    }
    if(!flag || perm) { cout << -1; return; }

    _uf uf(26); ind.resize(26);
    for(int i = 0;i < 26;i++){
        if(tf[i] == -1) continue;
        if(tf[i] != i) result++;
        ind[tf[i]]++;
        uf.merge(i, tf[i]);
    }

    vector <ll> g[26];
    for(int i = 0;i < 26;i++){
        g[uf.find(i)].push_back(i);
    }

    for(int i = 0;i < 26;i++){
        bool cy = 1;
        for(auto& j : g[i]){
            cy &= (ind[j] == 1);
        }
        if(cy && g[i].size() > 1) result++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

