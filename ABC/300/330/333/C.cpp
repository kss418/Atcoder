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
ll a[MAX], cnt;
vector <ll> arr;

void bt(ll cur){
    if(arr.size() == cur - 1){
        if(++cnt == n) {
            for(auto& i : arr) cout << i;
            cout << 3; 
        }
        return;
    }
    
    for(int i = (arr.empty() ? 1 : arr.back());i <= 3;i++){
        arr.push_back(i);
        bt(cur);
        arr.pop_back();
    }
}

void run(){
    cin >> n; ll num = 1;
    while(1){
        bt(num); num++;
        if(cnt >= n) break;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
