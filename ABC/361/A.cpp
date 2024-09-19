#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        cout << t << " ";
        if (i == m) cout << k << " ";
    }
    

    return 0;
}
