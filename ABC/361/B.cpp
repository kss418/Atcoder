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

    ll x1[2], x2[2], y1[2], y2[2], z1[2], z2[2],cnt =0;
    for (int i = 0; i < 2; i++) {
        cin >> x1[i] >> y1[i] >> z1[i];
        cin >> x2[i] >> y2[i] >> z2[i];
    }

    if (x2[0] > x1[1] && x2[0] < x2[1]) cnt++;
    if (y2[0] > y1[1] && y2[0] < y2[1]) cnt++;
    if (z2[0] > z1[1] && z2[0] < z2[1]) cnt++;
    if (x2[1] > x1[0] && x2[1] < x2[0]) cnt++;
    if (y2[1] > y1[0] && y2[1] < y2[0]) cnt++;
    if (z2[1] > z1[0] && z2[1] < z2[0]) cnt++;

    if (cnt == 3) cout << "Yes";
    else cout << "No";

    return 0;
}
