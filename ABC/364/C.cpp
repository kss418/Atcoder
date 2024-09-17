#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll a[MAX], b[MAX];


int main()
{
    fastio;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    ll result = n;
    sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
    sort(b + 1, b + n + 1); reverse(b + 1, b + n + 1);

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i]; if (sum <= m) continue;
        result = min<ll>(result, i); break;
    }
 
    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += b[i]; if (sum <= k) continue;
        result = min<ll>(result, i); break;
    }
    cout << result;


    return 0;
}
