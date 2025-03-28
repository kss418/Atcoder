#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
vector <pll> adj[MAX];
ll dp[MAX], len;

void dfs(ll cur, ll pre) {
	ll curn = 0;
	priority_queue <ll> pq;
	for (auto& i : adj[cur]) {
		ll nxt = i.first;
		ll cst = i.second;
		if (nxt == pre) continue;
		dfs(nxt, cur); pq.push(dp[nxt] + cst);
		dp[cur] = max(dp[cur], dp[nxt] + cst);
	}

	ll fi = 0;
	if (!pq.empty()) {
		fi = pq.top();
		pq.pop();
	}

	ll se = 0;
	if (!pq.empty()) {
		se = pq.top();
	}


	len = max(fi + se, len);
}

int main() {
    fastio;

    cin >> n; ll result = 0;
    for (int i = 1; i < n; i++) {
        ll st, en, c;
        cin >> st >> en >> c;
        adj[st].push_back({ en, c });
        adj[en].push_back({ st, c });
        result += 2 * c;
    }

    dfs(1, -1);
	cout << result - len;


    return 0;
}
