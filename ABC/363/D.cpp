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
constexpr ll MAX = 21;
constexpr ll MOD = 998244353;

ll mul(ll cur) {
    ll ret = 1;
    for (int i = 1; i <= cur; i++) ret *= 10;
    
    return ret;
}

int main() {
    fastio;

    cin >> n; n--;
    if (!n) {
        cout << 0; return 0;
    }

    for (int i = 1; i <= 36; i++) {
        ll div = (i + 1) / 2;
        if (n <= 9 * mul(div - 1)) {
            string result = to_string(mul(div - 1) + n - 1);
            result.resize(i, ' ');
            for (int j = div; j < i; j++) result[j] = result[i - j - 1];
            cout << result; return 0;
        }
        else n -= 9 * mul(div - 1);
    }

    
    return 0;
}
