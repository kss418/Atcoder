#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll arr[MAX];

ll dm(ll num) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += min(arr[i], num);

    if (sum <= m) return 1;
    return 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ll st = 0, en = 2 * 1e14 + 1;
    while (en > st) {
        ll mid = (st + en + 1) >> 1;
        if (dm(mid)) st = mid;
        else en = mid - 1;
    }

    if (st == 2 * 1e14 + 1) cout << "infinite";
    else cout << st;

  
    return 0;
}
