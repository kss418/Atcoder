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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 998244353;
string st[MAX];
bool ux[MAX], uy[MAX];

int main() {
    fastio;

    for(int i = 0;i < 8;i++) cin >> st[i];

    for(int i = 0;i < 8;i++){
        for(int j = 0;j < 8;j++){
            if(st[i][j] == '.') continue;
            ux[j] = uy[i] = 1; 
        }
    }

    ll cx = 0, cy = 0;
    for(int i = 0;i < 8;i++){
        if(!ux[i]) cx++;
        if(!uy[i]) cy++;
    }

    cout << cx * cy;


    return 0;
}
