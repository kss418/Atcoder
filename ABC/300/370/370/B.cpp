#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX][MAX];

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cin >> arr[i][j];
    }

    ll cur = 1;
    for (int i = 1; i <= n; i++) {
        if (cur >= i) cur = arr[cur][i];
        else cur = arr[i][cur];
    }

    cout << cur;


    return 0;
}
