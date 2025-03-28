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
map <ll, ll> nxt, pre;

void insert(ll idx, ll v){
    if(nxt[idx] != -1) pre[nxt[idx]] = v;
    nxt[v] = nxt[idx];
    nxt[idx] = v; pre[v] = idx;
}

void erase(ll idx){
    if(nxt[idx] != -1) pre[nxt[idx]] = pre[idx];
    if(pre[idx] != -1) nxt[pre[idx]] = nxt[idx];
    nxt[idx] = 0; pre[idx] = 0;
}

int main() {
    fastio;

    cin >> n; 
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) nxt[a[i]] = a[i + 1];
    for(int i = 2;i <= n;i++) pre[a[i]] = a[i - 1];
    nxt[a[n]] = -1; pre[a[1]] = -1;
    
    cin >> m;
    while(m--){
        ll op, idx; cin >> op >> idx;
        if(op == 1){
            ll v; cin >> v;
            insert(idx, v);
        }
        else erase(idx);
    }

    for(auto& i : pre){
        if(i.y != -1) continue;
        ll cur = i.x;
        while(cur != -1){
            cout << cur << " ";
            cur = nxt[cur];
        }
    }

     
    return 0;
}
