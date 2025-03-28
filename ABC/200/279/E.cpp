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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], pos[MAX];

int main() {
    fastio;

    cin >> n >> m; 
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1;i <= n;i++) b[i] = i;

    for(int i = 1;i <= m;i++) swap(b[a[i]], b[a[i] + 1]);
    for(int i = 1;i <= n;i++) pos[b[i]] = i;

    for(int i = 1;i <= n;i++) b[i] = i;
    for(int i = 1;i <= m;i++){
        if(b[a[i]] == 1) cout << pos[b[a[i] + 1]] << "\n";
        else if(b[a[i] + 1] == 1) cout << pos[b[a[i]]] << "\n";
        else cout << pos[1] << "\n";

        swap(b[a[i]], b[a[i] + 1]);
    }


    return 0;
}
