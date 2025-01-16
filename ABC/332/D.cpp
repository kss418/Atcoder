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
constexpr ll MAX = 6; // SET MAX SIZE
constexpr ll MOD = 998244353;

class node{
public:
    vector<vector<ll>> arr;
    node(){ arr.resize(n, vector<ll>(m, 0)); }
    bool operator <(const node& ot) const{
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(arr[i][j] != ot.arr[i][j]) return arr[i][j] < ot.arr[i][j];
            }
        }
        return 0;
    }
};
deque <pair<node, ll>> q;
map <node, ll> d;


void run(){
    cin >> n >> m; node a, b;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) cin >> a.arr[i][j];
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) cin >> b.arr[i][j];
    }

    q.push_back({a, 0});
    while(!q.empty()){
        auto[cur, cd] = q.front(); q.pop_front();
        if(!d.count(cur)) d[cur] = INF;
        if(d[cur] <= cd) continue; d[cur] = cd;

        for(int i = 0;i < n - 1;i++){
            node nxt = cur;
            swap(nxt.arr[i], nxt.arr[i + 1]);
            q.push_back({nxt, cd + 1});
        }

        for(int i = 0;i < m - 1;i++){
            node nxt = cur;
            for(int j = 0;j < n;j++) swap(nxt.arr[j][i], nxt.arr[j][i + 1]);
            q.push_back({nxt, cd + 1});
        }
    }

    if(!d.count(b)) d[b] = INF;
    cout << (d[b] == INF ? -1 : d[b]);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

