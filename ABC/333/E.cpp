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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
multiset <ll> ms;
vector <ll> result;
ll cnt;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    for(int i = n;i >= 1;i--){
        if(a[i].x == 1) {
            if(!ms.count(a[i].y)) result.push_back(0);
            else{
                result.push_back(1);
                ms.erase(ms.find(a[i].y));
            }
        }
        else ms.insert(a[i].y);
        cnt = max<ll>(cnt, ms.size());
    }

    if(!ms.empty()) cout << -1;
    else {
        cout << cnt << "\n"; reverse(all(result));
        for(auto& i : result) cout << i << " ";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
