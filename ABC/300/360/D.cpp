#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll x[MAX];
vector <ll> arr[2];

int main() {
    fastio;

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) cin >> x[i];

    for (int i = 1; i <= n; i++) arr[s[i - 1] - '0'].push_back(x[i]);
    sort(arr[0].begin(), arr[0].end()); sort(arr[1].begin(), arr[1].end());

    ll result = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] - '0' == 0) continue;
        ll op = (s[i - 1] - '0') ^ 1;
        auto l = upper_bound(arr[op].begin(), arr[op].end(), x[i]);
        auto r = upper_bound(arr[op].begin(), arr[op].end(), x[i] + 2 * m);

        result += (r - arr[op].begin()) - (l - arr[op].begin());
    }

    cout << result;


    return 0;
}
