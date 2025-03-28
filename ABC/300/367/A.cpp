#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
ll arr[MAX];


int main()
{
    fastio;
    cin >> n >> m >> k;
    if (k > m) {
        if (n >= k || n <= m) cout << "Yes";
        else cout << "No";
    }
    else {
        if (n + 24 >= k + 24 || n + 24 <= m) cout << "Yes";
        else cout << "No";
    }


    return 0;
}
