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

class node{
public:
    ll p, a, b;
};
node arr[MAX];
ll a[1010];

class _uf { 
public:
    ll n; vector <ll> p, sz;
    
    _uf(){}
    _uf(ll n) {  
        this->n = n;
        p.resize(n + 1, -1); sz.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        p[b] = a;
    }

    ll size(ll num){ return sz[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void clear(){ p.assign(n + 1, -1); sz.assign(n + 1, 1); }
}; 

vector <ll> nxt[1010];
void run(){
    cin >> n; _uf uf(5010101);
    ll sum = 0;
    for(int i = 1;i <= n;i++) cin >> arr[i].p >> arr[i].a >> arr[i].b;

    for(int i = 0;i <= 1000;i++) a[i] = i;
    for(int i = 1;i <= n;i++){
        auto& [v, pl, mi] = arr[i]; sum += mi;
        for(int j = 0;j <= 1000;j++){
            if(a[j] == -1) continue;
            if(v >= j) nxt[j + pl].push_back(a[j]);
            else nxt[max(j - mi, 0ll)].push_back(a[j]);
        }

        for(int j = 501;j <= 1000;j++){
            nxt[j].push_back(j + sum);
        }

        for(int j = 0;j <= 1000;j++){
            if(nxt[j].size() > 1) for(auto& k : nxt[j]){
                uf.merge(nxt[j][0], k);
            }

            if(nxt[j].empty()) a[j] = -1;
            else a[j] = nxt[j][0];
        }

        for(int j = 0;j <= 1000;j++) nxt[j].clear();
    }

    cin >> m;
    while(m--){
        ll x; cin >> x;
        if(x - sum > 500) { cout << x - sum << "\n"; continue; }
        for(int i = 0;i <= 1000;i++){
            if(a[i] == -1) continue;
            if(!uf.same(a[i], x)) continue;
            cout << i << "\n"; break;
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}