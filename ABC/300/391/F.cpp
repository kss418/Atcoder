#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], c[MAX];
ll da[3] = {-1, 0, 0}, db[3] = {0, -1, 0}, dc[3] = {0, 0, -1};

class node{
public:
    ll a, b, c;
    bool operator < (const node& ot) const{
        if(a != ot.a) return a < ot.a;
        if(b != ot.b) return b < ot.b;
        return c < ot.c;
    }
}; set <node> v;
priority_queue <pair<ll, node>> pq;

ll cal(ll ai, ll bi, ll ci){
    return a[ai] * b[bi] + b[bi] * c[ci] + c[ci] * a[ai];
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i]; sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++) cin >> b[i]; sort(b + 1, b + n + 1);
    for(int i = 1;i <= n;i++) cin >> c[i]; sort(c + 1, c + n + 1);

    pq.push({cal(n, n, n), {n, n, n}});
    while(!pq.empty()){
        auto[cd, cn] = pq.top(); pq.pop();
        auto[ca, cb, cc] = cn;
        if(v.count(cn)) continue; m--;
        if(!m) { cout << cd; return; }
        v.insert(cn);

        for(int i = 0;i < 3;i++){
            ll na = ca + da[i], nb = cb + db[i], nc = cc + dc[i];
            if(na <= 0 || nb <= 0 || nc <= 0) continue;
            pq.push({cal(na, nb, nc), {na, nb, nc}});
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

