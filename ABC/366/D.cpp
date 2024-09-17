#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
ll arr[MAX][MAX][MAX];
ll sum[MAX][MAX][MAX];



int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) cin >> arr[i][j][k];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                sum[i][j][k] = sum[i][j][k - 1] + sum[i][j - 1][k] + sum[i - 1][j][k];
                sum[i][j][k] -= sum[i][j - 1][k - 1] + sum[i - 1][j - 1][k] + sum[i - 1][j][k - 1];
                sum[i][j][k] += arr[i][j][k] + sum[i - 1][j - 1][k - 1];
            }
        }
    }



    cin >> t;
    while (t--) {
        ll x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        ll result = sum[x2][y2][z2] - sum[x1 - 1][y2][z2] - sum[x2][y1 - 1][z2] - sum[x2][y2][z1 - 1];
        result += sum[x1 - 1][y1 - 1][z2] + sum[x1 - 1][y2][z1 - 1] + sum[x2][y1 - 1][z1 - 1];
        result -= sum[x1 - 1][y1 - 1][z1 - 1];
        cout << result << '\n';
    }



    return 0;
}
