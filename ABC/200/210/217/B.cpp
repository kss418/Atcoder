#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 3;
constexpr ll MOD = 998244353;
string st[MAX];
map <string, bool> arr;
vector <string> a = { "ABC", "ARC", "AGC", "AHC"};

int main() {
    fastio;

    for(int i = 0;i < 3;i++) {
        cin >> st[i];
        arr[st[i]] = 1;
    }
    
    for(auto& i : a){
        if(arr[i]) continue;
        cout << i;
    }


    return 0;
}
