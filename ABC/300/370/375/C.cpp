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
constexpr ll MAX = 3010;
constexpr ll MOD = 998244353;
string st[MAX], nxt[MAX];


int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++) nxt[i].resize(n);
    
    ll cnt = 0;
    for(int i = 0;i < n / 2;i++){
        cnt++;
        for(int j = 1;j <= cnt % 4;j++){ 
            for(int k = i;k < n - i;k++){
                nxt[i][k] = st[n - k - 1][i]; 
                nxt[n - i - 1][k] = st[n - k - 1][n - i - 1];
                nxt[k][i] = st[n - i - 1][k];
                nxt[k][n - i - 1] = st[i][k];
            }

            for(int k = i;k < n - i;k++){
                st[i][k] = nxt[i][k];
                st[n - i - 1][k] = nxt[n - i - 1][k];
                st[k][i] = nxt[k][i];
                st[k][n - i - 1] = nxt[k][n - i - 1];
            }
        }
    }

    for(int i = 0;i < n;i++){
       for(int j = 0;j < n;j++) cout << st[i][j];
        cout << "\n";
    }


    return 0;
}
