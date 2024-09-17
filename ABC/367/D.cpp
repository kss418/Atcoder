#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX], sum[2 * MAX];
ll mod[1010101], result[2 * MAX];


int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) sum[i] = arr[i] + sum[i - 1];
    for (int i = 1; i <= n; i++) sum[n + i] = arr[i] + sum[n + i - 1];

    mod[0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (i >= n) mod[sum[i - n] % m]--;
        result[i] = mod[sum[i] % m];
        if (i > n) result[i] -= result[i - n];
        mod[sum[i] % m]++;
    }

    ll ret = 0;
    for (int i = 1; i <= 2 * n; i++) ret += result[i];

    cout << ret;


    return 0;
}
