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
ll a[MAX];
vector <ll> arr[26];

ll lb(const vector <ll>& v, ll k){
    return lower_bound(all(v), k + 1) - v.begin();
}

int main() {
    fastio;
    
    string a, b; cin >> a >> b;
    for(int i = 0;i < a.size();i++) arr[a[i] - 'a'].push_back(i);
    ll flag = 1, fi = -1, se = -1;

    if(arr[b[0] - 'A'].empty()) flag = 0;
    else fi = arr[b[0] - 'A'][0];

    ll now = lb(arr[b[1] - 'A'], fi); 
    if(now >= arr[b[1] - 'A'].size()) flag = 0;
    else se = arr[b[1] - 'A'][now];

    if(b[2] == 'X'){
        if(flag) cout << "Yes";
        else cout << "No"; return 0;
    }

    now = lb(arr[b[2] - 'A'], se);
    if(now >= arr[b[2] - 'A'].size()) flag = 0;

    if(flag) cout << "Yes";
    else cout << "No";

     
    return 0;
}
