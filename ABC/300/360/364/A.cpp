#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
string st[MAX];


int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> st[i];

    ll result = 1;
    for (int i = 2; i < n; i++) {
        if (st[i] == "sweet" && st[i - 1] == "sweet") result = 0;
    }

    if (result) cout << "Yes";
    else cout << "No";


    return 0;
}
