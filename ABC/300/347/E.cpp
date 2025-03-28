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
ll sum[MAX], inq[MAX], cnt, la[MAX];
ll result[MAX];

int main() {
    fastio;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) la[i] = 1;
    for (int i = 1; i <= m; i++) {
        cin >> k;
        if (inq[k]) cnt--, inq[k] = 0;
        else cnt++, inq[k] = 1;

        sum[i] = sum[i - 1] + cnt;
        if (inq[k]) la[k] = i;
        else result[k] += sum[i - 1] - sum[la[k] - 1];
    }
    for (int i = 1; i <= n; i++) if(inq[i]) result[i] += sum[m] - sum[la[i] - 1];

    for (int i = 1; i <= n; i++) cout << result[i] << " ";
  

    return 0;
}
