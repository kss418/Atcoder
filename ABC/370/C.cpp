#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
vector <string> result;
pair<char, ll> arr[MAX];
ll chk[MAX];

int main() {
    fastio;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < b.size(); i++) {
        if (a[i] == b[i]) continue;
        if (a[i] < b[i]) continue;
        a[i] = b[i]; result.push_back(a);
    }

    for (int i = b.size(); i >= 0; i--) {
        if (a[i] == b[i]) continue;
        a[i] = b[i]; result.push_back(a);
    }

    cout << result.size() << "\n";
    for (auto& i : result) cout << i << "\n";

    return 0;
}
