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
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
constexpr ll MID = 100100;
map <pll, ll> line;

template <typename T = int>
class _dij {
public:
    using ptl = pair <T, int>;
    ll n, seq = 1; vector <T> d;
    vector <ll> pre;
    vector <vector<ptl>> adj;
    priority_queue <ptl, vector<ptl>, greater<ptl>> pq;

    _dij(ll n) {
        this->n = n;
        d.resize(n + 1, 1e9); pre.resize(n + 1, -1);
        adj.resize(n + 1);
    }

    void add(ll st, ll en, ll c = 1) { // 양방향
        adj[st].push_back({ c,en });
        adj[en].push_back({ c,st });
        line[{st, en}] = line[{en, st}] = seq; seq++;
    }

    void addsol(ll st, ll en, ll c = 1) { // 단방향
        adj[st].push_back({ c,en });
    }

    void init(ll st, T fi = 0) {
        pre.clear(); d.clear();
        d.resize(n + 1, 1e9);

        d[st] = fi;
        pq.push({ d[st], st });

        while (!pq.empty()) {
            auto [cd, cur] = pq.top(); pq.pop();
            if (cd > d[cur]) continue;

            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (d[nxt] <= nd + cd) continue;

                d[nxt] = nd + cd;
                pre[nxt] = cur;
                pq.push({ d[nxt], nxt });
            }
        }
    }

    T ret(ll n) {
        return d[n];
    }
};
int a[MAX], cnt[MAX];
int dp[MAX][201010];

int main() {
    fastio;

    cin >> n >> m >> k; _dij dij(n);
    for(int i = 1;i <= m;i++) cin >> a[i];

    
    for(int i = 1;i < n;i++){
        ll u, v; cin >> u >> v;
        dij.add(u, v);
    }

    for(int i = 1;i < m;i++) {
        dij.init(a[i]);
        
        ll cur = a[i + 1];
        while(cur != a[i]){
            cnt[line[{cur, dij.pre[cur]}]]++;
            cur = dij.pre[cur];
        }
    }

    dp[0][MID] = 1;
    for(int i = 1;i < n;i++){
        for(int j = 0;j < 201010;j++){
            if(j >= cnt[i]) dp[i][j] += dp[i - 1][j - cnt[i]] % MOD;
            if(j + cnt[i] < 201010) dp[i][j] += dp[i - 1][j + cnt[i]] % MOD;
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n - 1][MID + k] % MOD;

    
    return 0;
}
