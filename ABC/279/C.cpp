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
ll n, m, k;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 401010;
constexpr ll MOD = 998244353;
string s[MAX], t[MAX];
string rs[MAX], rt[MAX];

int main() {
    fastio;

    ll h, w; cin >> h >> w;
    for(int i = 0; i < h;i++) cin >> s[i];
    for(int i = 0; i < h;i++) cin >> t[i];

    ll flag = 1;
    for(int i = 0;i < w;i++){
        for(int j = 0;j < h;j++){
            rs[i].push_back(s[j][i]);
            rt[i].push_back(t[j][i]);
        }
    }

    sort(rs, rs + w); sort(rt, rt + w);
    for(int i = 0;i < w;i++){
        if(rs[i] != rt[i]) flag = 0;
    }

    if(flag) cout << "Yes";
    else cout << "No";


    return 0;
}
