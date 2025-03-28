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
constexpr ll MAX = 555; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];

bool outrange(ll cy, ll cx){
    return (st[cy][cx] == '#');
}

bool dfs(ll cy, ll cx){
    if(outrange(cy, cx)) return 0;
    for(auto& i : s){
        if(i == 'L') cx--;
        else if(i == 'R') cx++;
        else if(i == 'U') cy--;
        else cy++;

        if(outrange(cy, cx)) return 0;
    }

    return 1;
}

void run(){
    cin >> n >> m >> k >> s;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll result = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) result += dfs(i, j);
    }

    cout << result;
}

int main() {
    fastio;

    // cin >> t;
    while(t--) run();
    

    return 0;
}
