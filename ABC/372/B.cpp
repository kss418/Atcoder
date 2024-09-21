#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 401010;
constexpr ll MOD = 1e9 + 7;
vector <ll> result;


int main() {
    fastio;
    
    cin >> n;
    ll cur = 1, cnt = 10;
    for (int i = 1; i <= 10; i++) cur *= 3;

    while (n) {
        while (n >= cur) {
            n -= cur;
            result.push_back(cnt);
        }

        cnt--; cur /= 3;
    }

    cout << result.size() << "\n";
    for (auto& i : result) cout << i << " ";

    return 0;
}
