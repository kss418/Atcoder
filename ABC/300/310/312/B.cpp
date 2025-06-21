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


int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    ll result = 0;
    for(int cy = 0;cy <= n - 9;cy++){
        for(int cx = 0;cx <= m - 9;cx++){
            string pre[4], nxt[4];
            for(int i = 0;i < 4;i++) pre[i] = st[i + cy].substr(cx, 4);
            for(int i = 5;i < 9;i++) nxt[i - 5] = st[i + cy].substr(cx + 5, 4);

            ll flag = 1;
            for(int i = 0;i < 3;i++) if(pre[i] != "###.") flag = 0;
            if(pre[4] != "...." || nxt[0] != "....") flag = 0;
            for(int i = 1;i < 4;i++) if(nxt[i] != ".###") flag = 0;

            if(flag) cout << cy + 1 << " " << cx + 1 << "\n";
        }
    }
    


    return 0;
}
