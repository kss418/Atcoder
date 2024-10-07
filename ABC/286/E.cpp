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
constexpr ll MAX = 301;
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX];
string st[MAX];

template <typename T = ll>
class _floyd { // ret(i,j) == INF 처리하기
public:
    ll n; vector <vector<T>> d, nxt;
    vector <ll> tr;

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
        nxt[st][en] = en; dp[st][en] = a[en];
    }

    void init() {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                    else if (d[i][j] == d[i][k] + d[k][j]) {
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
                    }
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

int main() {
    fastio;

    cin >> n; _floyd floyd(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) {
        cin >> st[i];
        for(int j = 0;j < n;j++){
            if(st[i][j] == 'N') continue;
            floyd.addsol(i, j);
        }
    }
    floyd.init();

    ll q; cin >> q;
    while(q--){
        ll u, v; cin >> u >> v;
        u--; v--; ll d = floyd.ret(u, v);

        if(d >= INF) cout << "Impossible\n";
        else cout << d << " " << dp[u][v] + a[u] << "\n";
    }

    return 0;
}
