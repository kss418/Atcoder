#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
pll arr[MAX];


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].first, arr[i].second = i;
    sort(arr + 1, arr + n + 1);
    reverse(arr + 1, arr + n + 1);

    cout << arr[2].second;
  
    return 0;
}
