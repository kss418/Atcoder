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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> adj[MAX];
ll dp[MAX][1ll << MAX];

template <typename T = ll>
class _floyd { // ret(i,j) == INF 처리하기
public:
    ll n; vector <vector<T>> d, nxt;
    vector <ll> tr;

    _floyd(){}
    _floyd(ll n) {
        this->n = n;
        d.resize(n + 1, vector<T>(n + 1, INF));
        nxt.resize(n + 1, vector<T>(n + 1, 0));
    }

    void add(ll st, ll en, T c = 1) { //양방향
        d[st][en] = min(d[st][en], c);
        d[en][st] = min(d[en][st], c);
        nxt[st][en] = en; nxt[en][st] = st;
    }

    void addsol(ll st, ll en, T c = 1) { //단방향
        d[st][en] = min(d[st][en], c);
        nxt[st][en] = en;
    }

    void init() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][j] <= d[i][k] + d[k][j]) continue;
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    T ret(ll st, ll en) {
        return d[st][en];
    }

    vector <ll> track(ll st, ll en) {
        ll cur = st; tr.clear();

        while (cur != en) {
            tr.push_back(cur);
            cur = nxt[cur][en];
        }
        tr.push_back(en);

        return tr;
    }
};
_floyd floyd;

void run(){
    cin >> n >> m; floyd = {n};
    for(int i = 1;i <= m;i++){
        ll s, e, c; cin >> s >> e >> c;
        s--; e--;
        adj[s].push_back({e, c});
        floyd.addsol(s, e, c);
    }
    floyd.init(); memset(dp, 0x3f, sizeof(dp));

    for(int i = 0;i < n;i++) dp[i][1ll << i] = 0;
    for(int cv = 1;cv < (1ll << n) - 1;cv++){
        for(int cur = 0;cur < n;cur++){
            if(~cv >> cur & 1) continue;
            if(dp[cur][cv] == INF) continue;            
            for(int nxt = 0;nxt < n;nxt++){
                if(cv >> nxt & 1) continue;
                if(floyd.ret(cur, nxt) == INF) continue;
                ll nv = cv | (1ll << nxt);
                dp[nxt][nv] = min(dp[nxt][nv], dp[cur][cv] + floyd.ret(cur, nxt));
            }
        }
    }

    ll result = INF;
    for(int i = 0;i < n;i++) result = min(result, dp[i][(1ll << n) - 1]);

    if(result == INF) cout << "No";
    else cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}