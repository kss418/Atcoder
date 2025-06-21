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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;

int main() {
    fastio;

    cin >> n >> m >> k;
    ll kc = 0;
    for (ll i = 0; i < 61; i++) {
        if (k & (1ll << i)) kc++;
    }

    ll same = (n + m - kc);
    if (same % 2 || same < 0) { cout << -1; return 0; }
    same >>= 1;

    ll a = 0, b = 0;
    n -= same; m -= same;
    if (n < 0 || m < 0) { cout << -1; return 0; }

    for (ll i = 0; i < 61; i++) {
        if (k & (1ll << i)) {
            if (m) { b |= (1ll << i); m--; }
            else if (n) { a |= (1ll << i); n--; }
        }
        else if (same) {
            a |= (1ll << i); b |= (1ll << i);
            same--;
        }
    }
    
    if (same || n || m) { cout << -1; return 0; }

    cout << a << " " << b;


    return 0;
}
