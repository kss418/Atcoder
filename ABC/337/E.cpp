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
bitset<101> bs[MAX];
vector <ll> arr[10];

void run(){
    cin >> n; n--; ll mx = 0;
    for(int i = 1;(1ll << i) <= n;i++) mx++;
    cout << mx + 1 << endl;

    for(int i = 0;i <= mx;i++){
        ll now = (1ll << i);
        for(int j = 0;j <= n;j++) {
            if(now & j) {
                arr[i].push_back(j + 1);
                bs[i].flip(j + 1);
            }
        }
    }

    for(int i = 0;i <= mx;i++){
        cout << arr[i].size() << " ";
        for(auto& j : arr[i]) cout << j << " ";
        cout << endl;
    }

    cin >> s;
    bitset<101> ret; ret.set();
    for(int i = 0;i <= mx;i++){
        if(s[i] == '1') ret &= bs[i];
        else ret &= ~bs[i];
    }

    for(int i = 1;i <= n + 1;i++){
        if(ret[i]) cout << i;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
