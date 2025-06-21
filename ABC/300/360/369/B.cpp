#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
char c[MAX];
ll dp[2];
vector <ll> arr[2];

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m >> c[i];
        if (c[i] == 'L') arr[0].push_back(m);
        else arr[1].push_back(m);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < arr[i].size(); j++) {
            dp[i] += abs(arr[i][j] - arr[i][j - 1]);
        }
    }

    cout << dp[0] + dp[1];
   

    return 0;
}
