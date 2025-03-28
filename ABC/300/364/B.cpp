#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51;
char arr[MAX][MAX];

int main()
{
    fastio;
    cin >> m >> n;
    ll x, y;

    cin >> y >> x;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) cin >> arr[i][j];
    }
    cin >> s;

    for (auto& i : s) {
        ll nx = x, ny = y;
        if (i == 'U') ny--;
        else if (i == 'D') ny++;
        else if (i == 'L') nx--; 
        else nx++;

        if (ny > m || ny <= 0 || nx > n || nx <= 0) continue;
        if (arr[ny][nx] == '#') continue;
        x = nx; y = ny;
    }
    
    cout << y << " " << x;


    return 0;
}
