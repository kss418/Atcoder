#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll l[MAX], r[MAX];
ll sl, sr, result[MAX];

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    for (int i = 1; i <= n; i++) {
        sl += l[i]; sr += r[i];
    }

    ll diff = -sl;
    if (sl <= 0 && sr >= 0) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            if (!diff) cout << l[i] << " ";
            else {
                ll cur = min(l[i] + diff, r[i]);
                diff -= cur - l[i];
                cout << cur << " ";
            }
        }
    }
    else cout << "No";
    

    return 0;
}
