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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll sum[MAX][MAX];

ll query(ll cy, ll cx){
    if(cy < 0 || cx < 0) return 0;
    ll mx = (cy / n) * (cx / n), ret = mx * sum[n - 1][n - 1];
    ret += sum[cy % n][n - 1] * (cx / n) + sum[n - 1][cx % n] * (cy / n);
    return ret += sum[cy % n][cx % n];
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            sum[i][j] = (i ? sum[i - 1][j] : 0) + (j ? sum[i][j - 1] : 0) + (st[i][j] == 'B');
            sum[i][j] -= (i && j ? sum[i - 1][j - 1] : 0);
        }
    }

    while(m--){
        ll y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << query(y2, x2) - query(y2, x1 - 1) - query(y1 - 1, x2) + query(y1 - 1, x1 - 1) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

