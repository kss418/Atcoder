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
constexpr ll MAX = 31;
constexpr ll MOD = 998244353;
ll num[MAX];

int main() {
    fastio;

    cin >> s;
    for(int i = 0;i < 26;i++){
        num[s[i] - 'A'] = i;
    }

    ll result = 0, cur = num[0];
    for(int i = 0;i < 26;i++){
        result += abs(cur - num[i]);
        cur = num[i];
    }

    cout << result;

  
    return 0;
}
