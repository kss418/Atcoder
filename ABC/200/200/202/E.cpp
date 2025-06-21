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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX], arr[MAX];
ll p[MAX], seq = 0;
ll in[MAX], out[MAX];

void dfs(ll cur, ll d) {
	in[cur] = ++seq; arr[d].push_back(seq);
	for (auto nxt : adj[cur]) dfs(nxt, d + 1);
	out[cur] = seq;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 2;i <= n;i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    dfs(1, 0);

    ll q; cin >> q;
    while(q--){
        ll mid, d; cin >> mid >> d;
        auto low = lower_bound(all(arr[d]), in[mid]);
        auto hi = upper_bound(all(arr[d]), out[mid]);
        cout << hi - low << "\n";
    }
    

    return 0;
}
