#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = n - m + 1; i <= n; i++) cout << arr[i] << " ";
    for (int i = 1; i < n - m + 1; i++) cout << arr[i] << " ";
    

    
    return 0;
}
