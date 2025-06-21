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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX], num[MAX];
pll q[MAX];
vector <ll> adj[MAX];

class _scc { // 1-based index
public:
    ll n, dcnt = 0, scnt = 0;
    vector <ll> d, sn, ind; // dfsn, scc번호, ind
    vector<vector<ll>> adj, scc; // 간선, scc
    vector <bool> fin;
    stack <ll> st;
    vector <set <ll>> sccset; // 위상정렬 간선

    _scc(ll n) {
        this->n = n;
        d.resize(n + 1); fin.resize(n + 1);
        adj.resize(n + 1); sn.resize(n + 1);
    }

    void add(ll st, ll en) {
        adj[st].push_back(en);
    }

    ll dfs(ll cur) {
        d[cur] = ++dcnt;
        st.push(cur);

        ll mn = d[cur];
        for (auto& nxt : adj[cur]) {
            if (!d[nxt]) mn = min(mn, dfs(nxt));
            else if (!fin[nxt]) mn = min(mn, d[nxt]);
        }

        if (mn == d[cur]) {
            vector <ll> curscc;
            while (1) {
                ll t = st.top(); st.pop();
                curscc.push_back(t);
                fin[t] = 1; sn[t] = scnt;
                if (t == cur) break;
            }

            sort(curscc.begin(), curscc.end());
            scc.push_back(curscc); scnt++;
        }

        return mn;
    }

    void init() {
        for (int i = 1; i <= n; i++) {
            if (d[i]) continue;
            dfs(i);
        }
    }

    vector <vector <ll>> ret() { // scc 반환
        return scc;
    }

    ll num(ll a) { // scc 번호 반환
        return sn[a];
    }

    vector <ll> top() { //위상정렬
        deque <ll> q; vector <ll> ts;
        sccset.resize(n + 1); ind.resize(n + 1);

        for (auto& i : scc) {
            for (auto& cur : i) {
                for (auto nxt : adj[cur]) {
                    if (num(cur) == num(nxt)) continue;
                    if (sccset[num(cur)].count(num(nxt))) continue;
                    sccset[num(cur)].insert(num(nxt));
                    ind[num(nxt)]++;
                }
            }
        }

        for (int i = 0; i < scnt; i++) {
            if (ind[i]) continue;
            q.push_back(i);
        }

        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            ts.push_back(cur);

            for (auto& nxt : sccset[cur]) {

                if (!--ind[nxt]) q.push_back(nxt);
            }
        }

        return ts;
    }
};

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = -INF;
    
    for(auto& nxt : adj[cur]){
        ret = max(ret, solve(nxt) + 1);
    }

    return ret;
}

void run(){
    cin >> n >> m; _scc scc(n);
    for(int i = 1;i <= n;i++) cin >> a[i]; 
    for(int i = 1;i <= m;i++){
        ll s, e; cin >> s >> e;
        q[i] = {s, e};
        if(a[s] <= a[e]) scc.add(e, s);
        if(a[e] <= a[s]) scc.add(s, e);
    }
    scc.init(); memset(dp, -1, sizeof(dp));

    for(int i = 1;i <= m;i++){
        auto[s, e] = q[i];
        ll ns = scc.num(s), ne = scc.num(e);
        num[ns] = a[s]; num[ne] = a[e];
        if(num[ns] > num[ne]) adj[ns].push_back(ne);
        if(num[ne] > num[ns]) adj[ne].push_back(ns);
    }
    dp[scc.num(1)] = 1;

    cout << max(solve(scc.num(n)), 0ll);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

