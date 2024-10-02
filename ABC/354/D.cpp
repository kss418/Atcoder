#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 10101;
constexpr ll MOD = 998244353;
constexpr ll PL = 4e9;
ll si[2][4] = {{2,1,0,1}, {1,2,1,0}};


int main() {
    fastio;

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll result = 0;
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 4;j++){
            ll a = (x1 - j + PL - 1) / 4, b = (x2 - j + PL - 1) / 4;
            ll dx = b - a;
            a = (y1 - i + PL - 1) / 2, b = (y2 - i + PL - 1) / 2;
            ll dy = b - a;

            result += dx * dy * si[i][j];
        }
    }

    cout << result;
    

    return 0;
}
