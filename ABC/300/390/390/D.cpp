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
constexpr ll MAX = 13; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> a, vec;
vector <ll> num;
ll ret[MAX];

void bt(){
    ll mx = 0;
    for(auto& i : vec) mx = max(mx, i);
    if(vec.size() == n){
        memset(ret, 0, sizeof(ret));
        for(int i = 0;i < n;i++){
            ret[vec[i]] += a[i];
        }

        ll now = 0;
        for(int i = 1;i <= mx;i++) now ^= ret[i];
        num.push_back(now); return;
    }

    for(int i = 1;i <= mx + 1;i++){
        vec.push_back(i);
        bt();
        vec.pop_back();
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> m, a.push_back(m);
    bt();

    ll result = 1; sort(all(num));
    for(int i = 1;i < num.size();i++){
        if(num[i] == num[i - 1]) continue;
        result++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

