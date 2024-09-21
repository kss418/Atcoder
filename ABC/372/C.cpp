#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 401010;
constexpr ll MOD = 1e9 + 7;
vector <ll> result;


int main() {
    fastio;
    
    cin >> n >> m;
    cin >> s;

    ll result = 0;
    for (int i = 0; i < n - 2; i++) {
        if (s.substr(i, 3) == "ABC") result++;
    }

    while (m--) {
        char c;
        cin >> k >> c;
        k--; ll pre = 0;
        for (int i = k - 2; i <= k + 2; i++) {
            if (i < 0 || i >= n) continue;
            if (s.substr(i, 3) == "ABC") pre++;
        }
        s[k] = c;

        ll nxt = 0;
        for (int i = k - 2; i <= k + 2; i++) {
            if (i < 0 || i >= n) continue;
            if (s.substr(i, 3) == "ABC") nxt++;
        }

        result -= pre - nxt;
        cout << result << "\n";
    }

    return 0;
}
