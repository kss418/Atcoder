#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX];
vector <ll> diff;

int main() {
    fastio;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 2; i <= n; i++) diff.push_back(arr[i] - arr[i - 1]);

    ll result = 2 * n - 1;

    ll cnt = 2;
    for (int i = 1; i < diff.size(); i++) {
        if (diff[i] == diff[i - 1]) cnt++;
        else {
            if (cnt > 2) result += (cnt - 2) * (cnt - 1) / 2;
            cnt = 2;
        }
    }
    if (cnt > 2) result += (cnt - 2) * (cnt - 1) / 2;

    cout << result;

  
    return 0;
}
