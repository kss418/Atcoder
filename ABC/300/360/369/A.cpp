#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;
    cin >> n >> m;
    ll result = 0;
    for (int i = -300; i <= 300; i++) {
        vector <ll> cur;
        cur.push_back(n);
        cur.push_back(m);
        cur.push_back(i);
        sort(cur.begin(), cur.end());

        if (cur[1] - cur[0] == cur[2] - cur[1])result++;
    }

    cout << result;


    return 0;
}
