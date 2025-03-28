#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
ll arr[MAX], sum;
vector <ll> num;
vector <vector <ll>> result;

void bt(ll cnt) {
    if (cnt == n + 1) {
        if (sum % m == 0) result.push_back(num);
        return;
    }

    for (int i = 1; i <= arr[cnt]; i++) {
        sum += i; num.push_back(i);
        bt(cnt + 1);
        num.pop_back(); sum -= i;
    }
}


int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    bt(1);

    for (auto& i : result) {
        for (auto& j : i) cout << j << " ";
        cout << "\n";
    }

    return 0;
}
