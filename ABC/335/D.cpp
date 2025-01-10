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
constexpr ll MAX = 51; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll arr[MAX][MAX];
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool outrange(ll cy, ll cx){
    if(cy <= 0 || cx <= 0 || cy > n || cx > n) return 1;
    return arr[cy][cx];
}

void con(ll cy, ll cx, ll dir, ll num){
    if(cy == (n + 1) / 2 && cx == (n + 1) / 2) return;
    arr[cy][cx] = num;

    if(outrange(cy + dy[dir], cx + dx[dir])) dir = (dir + 1) % 4;
    ll ny = cy + dy[dir], nx = cx + dx[dir];
    con(ny, nx, dir, num + 1);
}

void run(){
    cin >> n; con(1, 1, 0, 1);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == (n + 1) / 2 && j == (n + 1) / 2) cout << "T" << " ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

