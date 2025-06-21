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
ll a[MAX], result[MAX];

class node{
public:
    ll st, itv, cnt, co, dest;
};
vector <node> adj[MAX];

int main() {
    fastio;

    cin >> n >> m;
    while(m--){
        ll st, itv, cnt, co, l, r;
        cin >> st >> itv >> cnt >> co >> l >> r;
        adj[r].push_back({st, itv, cnt, co, l});
    }

    priority_queue <pll> pq;
    pq.push({INF, n});
    memset(result, -1, sizeof(result));

    while(!pq.empty()){
        auto[cd, cur] = pq.top(); pq.pop();
        if(result[cur] >= cd) continue;
        result[cur] = cd;

        for(auto& nn : adj[cur]){
            auto[st, itv, cnt, co, nxt] = nn;
            ll now = -1;
            if(cd >= co + st) now = min((cd - co) - ((cd - co - st) % itv), st + itv * (cnt - 1));
            pq.push({now, nxt});
        }
    }

    for(int i = 1;i < n;i++){
        if(result[i] == -1) cout << "Unreachable\n";
        else cout << result[i] << "\n";
    }

     
    return 0;
}
