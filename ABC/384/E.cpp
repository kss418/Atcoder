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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 511; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
bool v[MAX][MAX];

class node{
public:
    __int128 v; ll y, x;
    bool operator >(const node& ot) const{
        return v > ot.v;
    }
};
priority_queue <node, vector<node>, greater<node>> pq;

ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
bool outrange(ll cy, ll cx){
    if(cy <= 0 || cx <= 0 || cy > n || cx > m) return 1;
    return v[cy][cx];
}

int main() {
    fastio;

    cin >> n >> m >> k; __int128 mul; mul = k;
    ll p, q; cin >> p >> q;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }  

    ll result = a[p][q]; v[p][q] = 1;
    for(int i = 0;i < 4;i++){
        ll ny = p + dy[i], nx = q + dx[i];
        if(outrange(ny, nx)) continue;
        pq.push({a[ny][nx], ny, nx});
    }

    while(!pq.empty()){
        auto[cv, cy, cx] = pq.top(); pq.pop();
        if(v[cy][cx]) continue; v[cy][cx] = 1;
        if(cv * mul >= result) continue;
        result += cv;

        for(int i = 0;i < 4;i++){
            ll ny = cy + dy[i], nx = cx + dx[i];
            if(outrange(ny, nx)) continue;
            pq.push({a[ny][nx], ny, nx});
        }
    }

    cout << result;

     
    return 0;
}
