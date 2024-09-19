#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];

int main() {
    fastio;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);

    ll st = 1, en = n - m;
    ll result = INF;
    for (int i = 0; i <= m; i++) {
        result = min(result, arr[en + i] - arr[st + i]);
    }

    cout << result;


    return 0;
}
