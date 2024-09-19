#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 15;
constexpr ll MOD = 1e9 + 7;
string a, b;
map <string, ll> dp;
deque <pair<string, ll>> q;

int main() {
    fastio;

    cin >> n >> a >> b;
    a.resize(n + 2); b.resize(n + 2);
    a[n] = '.', a[n + 1] = '.';
    b[n] = '.', b[n + 1] = '.';

    q.push_back({ a, 0 });
    while (!q.empty()) {
        auto [cur, cn] = q.front(); q.pop_front();
        if (dp.count(cur)) continue;
        dp[cur] = cn;

        ll mv = -1;
        for (int i = 0; i <= n; i++) if (cur[i] == '.' && cur[i + 1] == '.') mv = i;

        for (int i = 0; i <= n; i++) {
            if (cur[i] == '.' || cur[i + 1] == '.') continue;
            cur[mv] = cur[i]; cur[mv + 1] = cur[i + 1];
            cur[i] = '.'; cur[i + 1] = '.';

            if (!dp.count(cur)) q.push_back({ cur, cn + 1 });

            cur[i] = cur[mv]; cur[i + 1] = cur[mv + 1];
            cur[mv] = '.'; cur[mv + 1] = '.';
        }
    }

    if (dp.count(b)) cout << dp[b];
    else cout << -1;


    return 0;
}
