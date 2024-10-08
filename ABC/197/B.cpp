#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
string st[MAX];


int main() {
    fastio;

    ll h, w, x, y; cin >> h >> w >> y >> x;
    for(int i = 0;i < h;i++) cin >> st[i];
    x--; y--;

    ll result = 1;
    for(int i = y - 1;i >= 0;i--){
        if(st[i][x] == '#') break;
        result++;
    }

    for(int i = x - 1;i >= 0;i--){
        if(st[y][i] == '#') break;
        result++;
    }

    for(int i = y + 1;i < h;i++){
        if(st[i][x] == '#') break;
        result++;
    }

    for(int i = x + 1;i < w;i++){
        if(st[y][i] == '#') break;
        result++;
    }
    
    cout << result;


    return 0;
}
