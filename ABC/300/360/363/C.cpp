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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;

bool chk(string& s) {
    for (int i = 0; i < s.size() - m + 1; i++) {
        ll flag = 1;
        for (int j = 0; j < m / 2; j++) {
            if (s[i + j] == s[i + m - j - 1]) continue;
            flag = 0;
        }

        if (flag) return 1;
    }

    return 0;
}

int main() {
    fastio;

    cin >> n >> m >> s;
    sort(s.begin(), s.end());

    ll result = 0;
    while (1) {
        if (!chk(s)) result++;
        if (!next_permutation(all(s))) break;
    }

    cout << result;


    return 0;
}
