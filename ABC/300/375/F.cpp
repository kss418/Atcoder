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
        nxt[st][en] = en;
    }

    void init() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
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
tll line[101010];
set <ll> able;
vector <pll> query;
vector <ll> result;

int main() {
    fastio;

    ll q; cin >> n >> m >> q;
    _floyd floyd(n);
    for(int i = 1;i <= m;i++) {
        ll a, b, c; cin >> a >> b >> c;
        line[i] = {a, b, c};
        able.insert(i);
    }

    while(q--){
        ll num, x, y; cin >> num >> x;
        if(num == 1) {
            able.erase(x);
            query.push_back({x, -1});
        }
        else cin >> y, query.push_back({x, y});
    }

    for(auto& i : able){
        auto[s, e, c] = line[i];
        floyd.add(s, e, c);
    }
    floyd.init(); reverse(all(query));

    for(auto& i : query){
        auto[s, e] = i;
        if(e == -1){
            auto[st, en, co] = line[s];
            floyd.d[st][en] = floyd.d[en][st] = min(co, floyd.d[st][en]);
            floyd.d[st][st] = 0; floyd.d[en][en] = 0;
       
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    floyd.d[i][j] = min(floyd.d[i][j], floyd.d[i][st] + floyd.d[en][j] + co);
                    floyd.d[i][j] = min(floyd.d[i][j], floyd.d[i][en] + floyd.d[st][j] + co);
                }
            }
        }
        else{
            ll ret = floyd.ret(s, e);
            if(ret == INF) ret = -1;
            result.push_back(ret);
        }
    }
    reverse(all(result));

    for(auto& i : result) cout << i << "\n";
    

    return 0;
}
