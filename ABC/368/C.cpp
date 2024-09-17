#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ll cur = 1;
    for (int i = 1; i <= n; i++) {
        ll moc = arr[i] / 5;
        cur += 3 * moc;
        ll mod = arr[i] % 5;

        while (mod > 0) {
            if (cur % 3) mod--;
            else mod -= 3;
            cur++;
        }
    }

    cout << cur - 1;
    
    return 0;
}
