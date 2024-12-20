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
vector <ll> adj[MAX];
bool v[MAX];
deque <ll> q;


int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll l, r; cin >> l >> r;
        adj[l - 1].push_back(r);
        adj[r].push_back(l - 1);
    }
    
    q.push_back(0);
    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        if(v[cur]) continue; v[cur] = 1;

        for(auto& nxt : adj[cur]){
            if(v[nxt]) continue;
            q.push_back(nxt);
        }
    }
    
    if(v[n]) cout << "Yes";
    else cout << "No";


    return 0;
}
