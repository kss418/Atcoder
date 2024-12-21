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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll result = 0, v[MAX][MAX];

bool outrange(ll cy, ll cx){
    if(cy < 0 || cx < 0 || cy >= n || cx >= m) return 1;
    if(st[cy][cx] == '#') return 1;
    return 0;
}

int main() {
    fastio;

    ll cy, cx; cin >> n >> m >> cy >> cx; cy--; cx--;
    for(int i = 0;i < n;i++) cin >> st[i];
    cin >> s;

    for(auto& i : s){
        ll ny = cy, nx = cx;
        if(!v[cy][cx] && st[cy][cx] == '@') result++;
        v[cy][cx] = 1;

        if(i == 'L') nx--;
        else if(i == 'R') nx++;
        else if(i == 'D') ny++;
        else ny--;

        if(outrange(ny, nx)) continue;
        cy = ny; cx = nx;
        if(!v[cy][cx] && st[cy][cx] == '@') result++;
        v[cy][cx] = 1;
    }

    cout << cy + 1 << " " << cx + 1 << " " << result;

     
    return 0;
}
