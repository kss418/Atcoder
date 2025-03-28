#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 401;
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
        if (st == en) return 0;
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
tll node[201010];

int main() {
    fastio;

    cin >> n >> m;
    _floyd floyd(n);
    for (int i = 1;i <= m;i++) {
        ll s, e, c;
        cin >> s >> e >> c;
        floyd.add(s, e, c);

        node[i] = {s,e,c};
    }
    floyd.init();
    cin >> k;
    while(k--){
        ll num;
        cin >> num;
        vector <ll> q;
        for(int i = 1;i <= num;i++){
            cin >> t; q.push_back(t);
        }
        
        ll result = INF;
        sort(all(q));

        while(1){
            for(int num = 0;num <= (1 << q.size());num++){
                ll cur = 0, la = 1;
                ll flag = 1;

                for(int i = 0;i < q.size();i++){
                    auto [st,en,c] = node[q[i]];
                    if(num & (1 << i)) swap(st, en);

                    ll pl = floyd.ret(la, st);
                    if(pl >= INF) { flag = 0; break; }
                    cur += pl;
                    cur += c; la = en;
                }
                
                ll pl = floyd.ret(la, n);
                if(pl >= INF) flag = 0; cur += pl;

                if(flag) result = min(result, cur);
            }

            if(!next_permutation(all(q))) break;
        }

        cout << result << "\n";
    }


    return 0;
}
