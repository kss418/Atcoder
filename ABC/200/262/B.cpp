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
ll adj[MAX][MAX];


int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s][e] = adj[e][s] = 1;
    }

    ll result = 0;
    for(int a = 1;a <= n;a++){
        for(int b = a + 1;b <= n;b++){
            for(int c = b + 1;c <= n;c++){
                ll flag = adj[a][b] && adj[b][c] && adj[c][a];
                if(flag) result++;
            }
        }
    }

    cout << result;


    return 0;
}
