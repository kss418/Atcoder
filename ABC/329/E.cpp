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
string a, b;

bool match(ll idx){
    for(int i = 0;i < b.size();i++){
        if(a[idx + i] != b[i]) return 0;
    }
    return 1;
}

bool erase(ll idx){
    for(int i = 0;i < b.size();i++){
        if(a[idx + i] == '#') continue;
        if(a[idx + i] != b[i]) return 0;
    }
    return 1;
}

void run(){
    cin >> n >> m >> a >> b;
    for(int i = 0;i < a.size();i++){
        if(!match(i)) continue;
        for(int j = 0;j < b.size();j++) a[i + j] = '#';
    }

    for(int i = 0;i < a.size();i++){
        if(!erase(i)) continue;
        for(int j = 0;j < b.size();j++) a[i + j] = '#';
    }

    for(int i = a.size() - 1;i >= 0;i--){
        if(!erase(i)) continue;
        for(int j = 0;j < b.size();j++) a[i + j] = '#';
    }
    
    ll result = 1;
    for(auto& i : a) if(i != '#') result = 0;
    cout << (result ? "Yes" : "No");
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

