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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll cnt, c[MAX][MAX], result, red;
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
bool use[MAX * MAX];

class _inv {
public:
    _inv() {}
    ll pow_mod(ll a, ll b, ll c) {
        if (!b) return 1;
        ll ret = pow_mod(a, b / 2, c) % c;

        if (b % 2) return ((ret * ret) % c * (a % c)) % c;
        return (ret * ret) % c;
    }

    ll prime_inv(ll a, ll b) {
        return pow_mod(a, b - 2, b);
    }

    ll ret(ll a, ll b, ll m) { // (a * b^-1) % m 반환 m == prime
        return (a % m * prime_inv(b, m) % m) % m;
    }
};


bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

void dfs(ll cy, ll cx, ll col){
    if(outrange(cy, cx)) return;
    if(c[cy][cx]) return;
    if(st[cy][cx] == '.') return;
    c[cy][cx] = col;

    for(int i = 0;i < 4;i++) dfs(cy + dy[i], cx + dx[i], col);
}

void ff(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) {
            if(st[i][j] == '.') continue;
            if(c[i][j]) continue;
            dfs(i, j, ++cnt);
        }
    }
}

void solve(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '#') continue; red++;
            ll now = cnt;
            for(int k = 0;k < 4;k++){
                ll ny = i + dy[k], nx = j + dx[k];
                if(outrange(ny, nx)) continue;
                if(st[ny][nx] == '.') continue;
                if(use[c[ny][nx]]) continue;
                now--; use[c[ny][nx]] = 1;
            }

            for(int k = 0;k < 4;k++){
                ll ny = i + dy[k], nx = j + dx[k];
                if(outrange(ny, nx)) continue;
                use[c[ny][nx]] = 0;
            }

            result += now + 1;
        }
    }
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    ff(); solve(); _inv inv;
    cout << inv.ret(result, red, MOD);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

