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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
string st[MAX];
vector <char> fi = {'H', 'D', 'C', 'S'};
vector <char> se = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
map <string, bool> cnt;

int main() {
    fastio;

    cin >> n; ll flag = 1;
    for(int i = 0;i < n;i++) {
        cin >> st[i]; ll cur = 0;
        for(auto& j : fi) if(st[i][0] == j) cur++;
        for(auto& j : se) if(st[i][1] == j) cur++;
        if(cnt[st[i]]) flag = 0;
        cnt[st[i]] = 1;
        
        if(cur != 2) flag = 0;
    }

    if(flag) cout << "Yes";
    else cout << "No";
    

    return 0;
}
