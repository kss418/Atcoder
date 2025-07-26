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
pll a[MAX];
ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

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
}; _uf uf;
map <pll, ll> num;

bool outrange(ll cy, ll cx){
    return cy <= 0 || cx <= 0 || cy > n || cx > m;
}

bool chk(){
    if(uf.same(1, 3) || uf.same(2, 4)) return 1;
    if(uf.same(1, 2) || uf.same(3, 4)) return 1;
    return 0;
}

void run(){
    cin >> n >> m >> k; uf = {k + 4};
    for(int i = 1;i <= k;i++){
        cin >> a[i].x >> a[i].y;
        num[{a[i].x, a[i].y}] = i + 4;
    }

    for(int i = 1;i <= k;i++){
        auto& [cy, cx] = a[i];
        for(int j = 0;j < 8;j++){
            ll ny = cy + dy[j], nx = cx + dx[j];
            if(outrange(ny, nx)){
                if(ny <= 0) uf.merge(1, num[{cy, cx}]);
                else if(nx <= 0) uf.merge(2, num[{cy, cx}]);
                else if(ny > n) uf.merge(3, num[{cy, cx}]);
                else uf.merge(4, num[{cy, cx}]);
            }
            else if(num.count({ny, nx})){
                uf.merge(num[{cy, cx}], num[{ny, nx}]);
            }
        }
    }

    cout << (chk() ? "No" : "Yes");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}