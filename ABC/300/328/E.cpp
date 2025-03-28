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
ll result = INF, now, cnt[MAX];
class node{
public:
    ll s, e, c;
};
vector <node> arr;
vector <ll> vec;

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
    void clear(){ p.assign(n + 1, -1); si.assign(n + 1, -1); }
} uf;

bool chk(){
    uf.clear();
    for(auto& i : vec){
        auto&[s, e, c] = arr[i];
        if(uf.same(s, e)) return 0;
        uf.merge(s, e);
    }

    return 1;
}

void bt(){
    if(vec.size() == n - 1){
        if(chk()) result = min(result, now % k);
        return;
    }

    for(int i = (vec.empty() ? 0 : vec.back() + 1);i < arr.size();i++){
        auto[s, e, c] = arr[i];
        vec.push_back(i); now += c;
        bt();
        vec.pop_back(); now -= c;
    }
}

void run(){
    cin >> n >> m >> k; uf = {n};
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        arr.push_back({s, e, c});
    }

    bt(); cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

