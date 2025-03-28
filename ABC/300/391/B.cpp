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
constexpr ll MAX = 51; // SET MAX SIZE
constexpr ll MOD = 998244353;
string a[MAX], b[MAX];

bool match(ll cy, ll cx){
    if(cy + m > n || cx + m > n) return 0;
    for(int i = 0; i < m;i++){
        for(int j = 0; j < m;j++){
            if(a[i + cy][j + cx] != b[i][j]) return 0;
        }
    }

    return 1;
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) cin >> b[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(!match(i, j)) continue;
            cout << i + 1 << " " << j + 1; return;
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

