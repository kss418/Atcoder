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
ll a[MAX], cnt[MAX];
bool f[MAX];

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
        cnt[a] += cnt[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

void run(){
    cin >> n >> m; _uf uf(n);
    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll s, e; cin >> s >> e;
            uf.merge(s, e);
        }
        else if(op == 2){
            ll v; cin >> v;
            f[v] ^= 1;
            ll num = uf.find(v);
            cnt[num] += (f[v] ? 1 : -1);
        }
        else{
            ll x; cin >> x;
            ll num = uf.find(x);
            cout << (cnt[num] ? "Yes" : "No") << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}