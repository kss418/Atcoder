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
ll sum, mi;
deque <ll> sm, arr;

void run(){
    cin >> n;
    while(n--){
        ll op; cin >> op;
        if(op == 1){
            ll v; cin >> v;
            sum += v;
            sm.push_back(sum);
            arr.push_back(v);
        }
        else if(op == 2) {
            mi += arr.front();
            sm.pop_front();
            arr.pop_front();
        }
        else{
            ll idx; cin >> idx;
            if(idx == 1) cout << 0 << "\n";
            else cout << sm[idx - 2] - mi << "\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

