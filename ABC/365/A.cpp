#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;


int main()
{
    cin >> n;
    if (n % 4) cout << 365;
    else if (n % 4 && n % 100 == 0) cout << 366;
    else if (n % 100 == 0 && n % 400) cout << 365;
    else cout << 366;

  
    return 0;
}
