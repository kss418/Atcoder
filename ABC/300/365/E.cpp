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
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX];
ll cnt[MAX][31];

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 31; j++) {
            cnt[i][j] = cnt[i - 1][j];
            if (sum[i] & (1ll << j)) cnt[i][j]++;
        }
    }

    ll result = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 31; j++) {
            ll cur = 1ll << j;
            if (sum[i] & cur) result += cur * ((i - 1) - cnt[i - 2][j]);
            else result += cur * cnt[i - 2][j];
        }
    }
   

    cout << result;


    return 0;
}
