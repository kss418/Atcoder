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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
vector <vector <ll>> sx, sy;

void run(){
    cin >> n >> m >> k;
    sx.resize(n, vector<ll>(m, 0));
    sy.resize(n, vector<ll>(m, 0));

    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < m;j++){
            ll now = 0;
            if(st[i][j] == 'x') now = -1e9;
            else if(st[i][j] == 'o') now = 1;

            sx[i][j] = (j ? sx[i][j - 1] : 0) + now;
            sy[i][j] = (i ? sy[i - 1][j] : 0) + now;
        }
    }

    ll result = INF;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i >= k - 1){
                ll now = sy[i][j];
                ll pre = (i == k - 1 ? 0 : sy[i - k][j]);
                if(now - pre >= 0) result = min(result, k - now + pre); 
            }

            if(j >= k - 1){
                ll now = sx[i][j];
                ll pre = (j == k - 1 ? 0 : sx[i][j - k]);
                if(now - pre >= 0) result = min(result, k - now + pre); 
            }
        }
    }

    cout << (result >= INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
