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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
bool result[MAX][MAX];


void run(){
    cin >> n >> m >> k;
    ll cy = 0, cx = 0, dir = 0;

    while(k--){
        if(!result[cy][cx]) dir = (dir + 1) % 4;
        else dir = (dir + 3) % 4;
        result[cy][cx] ^= 1;

        cy += dy[dir]; cx += dx[dir];
        cy = (cy + n) % n; cx = (cx + m) % m;
    } 

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(result[i][j]) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
