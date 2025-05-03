#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 4010; // SET MAX SIZE
constexpr ll MOD = 998244353;

template <typename T = ll>
class _spfa {
public:
    using ptl = pair <T, ll>;
    ll n; vector <ll> pre, cnt;
    vector <T> d; vector <bool> in;
    deque <ll> q;
    vector <vector <ptl>> adj;

    _spfa(ll n) {
        this->n = n;
        pre.resize(n + 1, -1); d.resize(n + 1, INF);
        in.resize(n + 1); adj.resize(n + 1);
        cnt.resize(n + 1);
    }

    void addsol(ll st, ll en, T c = 1) { // 단방향
        adj[st].push_back({ c, en });
    }

    ll init(ll st, ll fi = 0) { // cycle 0 else 1 / fi = d[st]
        d[st] = fi; in[st] = 1;
        q.push_back(st);

        while (!q.empty()) {
            ll cur = q.front(); q.pop_front();
            in[cur] = 0; cnt[cur]++;
            ll cd = d[cur];
            if (cnt[cur] > n) return 0;

            for (auto& nn : adj[cur]) {
                auto [nd, nxt] = nn;
                if (d[nxt] <= nd + cd) continue;
                d[nxt] = nd + cd;
                pre[nxt] = cur;

                if (in[nxt]) continue;
                in[nxt] = 1;
                q.push_back(nxt);
            }
        }

        return 1;
    }

    T ret(ll num) { // 거리 반환
        return d[num];
    }

    vector <ll> track(ll st, ll en) { // st -> en 경로 반환
        vector <ll> ret;
        ll cur = en;
        while (cur != -1) {
            ret.push_back(cur);
            cur = pre[cur];
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

void run(){
    cin >> n >> m; _spfa spfa(n);
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        spfa.addsol(s - 1, e, c);
        spfa.addsol(e, s - 1, -c);
    }

    for(int i = 1;i <= n;i++) spfa.addsol(i, i - 1, -1);
    if(!spfa.init(n)){ cout << -1; return; }

    ll ret = -spfa.ret(0);
    cout << (ret == -INF ? -1 : ret) << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

