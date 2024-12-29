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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

int main() {
    fastio;
    
    cin >> m; ll result = 0;
    string st; cin >> s >> st;

    ll cnt = 0;
    if(s.size() == st.size()){
        for(int i = 0;i < s.size();i++){
            if(s[i] != st[i]) cnt++;
        }
    }
    else if(s.size() + 1 == st.size()){
        for(int i = 0;i < st.size();i++){
            if(s[i - cnt] != st[i]) cnt++;
            if(cnt >= 2) break;
        }
    }
    else if(s.size() == st.size() + 1){
        for(int i = 0;i < s.size();i++){
            if(s[i] != st[i - cnt]) cnt++;
            if(cnt >= 2) break;
        }
    }
    else cnt = 2;

    if(cnt <= 1) result = 1;

    if(result) cout << "Yes";
    else cout << "No";

     
    return 0;
}
