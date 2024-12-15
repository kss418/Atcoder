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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];
string st[MAX];

class _bfs { // 0-based index
public:
    ll n, m;
    ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    // ll dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
    // ll dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    class node {
    public:
        ll y, x;
        ll num() const{
            return y * 200 + x;
        }
        bool operator <(const node& ot) const{ 
            if(y != ot.y) return y < ot.y;
            return x < ot.x;
        }
    };
    deque <pair <node, ll>> q; vector <ll> v;
    _bfs(){}
    _bfs(ll n, ll m) { this->n = n; this->m = m; v.resize(40101, -1); }

    bool outrange(node cur){
        auto[cy, cx] = cur;
        if(cy < 0 || cx < 0 || cy >= n || cx >= m) return 1;
        if(st[cy][cx] == '#') return 1;
        return 0;
    }

    void init(node st) {
        q.push_back({st, 0});
        while (!q.empty()) {
            auto [cur, ce] = q.front(); q.pop_front();
            auto [cy, cx] = cur;
            if (v[cur.num()] >= ce) continue;
            ce = max(a[cy][cx], ce); v[cur.num()] = ce;

            if(ce <= 0) continue;
            for(int i = 0;i < 4;i++){
                ll nx = cx + dx[i], ny = cy + dy[i];
                node nxt = {ny, nx};
                if (outrange(nxt)) continue;
                q.push_back({nxt, ce - 1});
            }
        }
    }

    ll ret(node cur) { return v[cur.num()]; }
};


int main() {
    fastio;

    cin >> n >> m; _bfs bfs(n, m);
    for(int i = 0;i < n;i++) cin >> st[i];

    cin >> k;
    for(int i = 1;i <= k;i++){
        ll y, x, e; cin >> y >> x >> e;
        y--; x--; a[y][x] = e;
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] != 'S') continue;
            bfs.init({i, j});
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] != 'T') continue;
            ll ret = bfs.ret({i, j});
            if(ret == -1) cout << "No";
            else cout << "Yes";
        }
    }

     
    return 0;
}
