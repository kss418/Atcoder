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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
multiset <ll> arr;

int main() {
    fastio;

    cin >> n;
    while(n--){
        ll num, x, k; cin >> num >> x;
        if(num == 1) arr.insert(x);
        else if(num == 3){
            cin >> k;
            auto it = arr.lower_bound(x);

            ll flag = 1;
            if(it == arr.end()) flag = 0;
            for(int i = 1;i < k && flag;i++) {
                it++;
                if(it == arr.end()) flag = 0;
            }

            if(flag) cout << *it << "\n";
            else cout << -1 << "\n";
        }
        else{
            cin >> k;
            auto it = arr.upper_bound(x); 
            
            ll flag = 1;
            if(!arr.empty()) {
                if(it == arr.begin()) flag = 0;
                it--;
            }
            else flag = 0;

            for(int i = 1;i < k && flag;i++) {
                if(it == arr.begin()) flag = 0;
                it--;
            }

            if(flag) cout << *it << "\n";
            else cout << -1 << "\n";
        }
    }
    
    
    return 0;
}
