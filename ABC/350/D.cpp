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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
vector <ll> adj[MAX];
ll v[MAX], cnt, line;

void dfs(ll cur, ll pre) {
    if (v[cur]) return;
    v[cur] = 1; cnt++;

    for (auto& nxt : adj[cur]) {
        line++;
        if (nxt == pre) continue;
        dfs(nxt, cur); 
    }
}

int main() {
    fastio;

    cin >> n >> m;
    while (m--) {
        ll st, en;
        cin >> st >> en;
        adj[st].push_back(en);
        adj[en].push_back(st);
    }
    
    ll result = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i]) continue;
        cnt = 0; line = 0; dfs(i, -1);

        if (cnt <= 2) continue;
        result += ((cnt * (cnt - 1)) - line) >> 1;
    }

    cout << result;


    return 0;
}
