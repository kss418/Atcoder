#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;

    cin >> s;
    ll r, m;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'R') r = i;
        else if (s[i] == 'M') m = i;
    }

    if (r < m) cout << "Yes";
    else cout << "No";


    return 0;
}