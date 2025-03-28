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
ll arr[MAX], num[MAX];
vector <pll> result;

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; num[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == i) continue;
        result.push_back({ min<ll>(i, num[i]), max<ll>(i, num[i]) });
        swap(arr[i], arr[num[i]]); num[arr[num[i]]] = num[i]; num[i] = i;
    }

    cout << result.size() << '\n';
    for (auto& i : result) cout << i.x << " " << i.y << "\n";


    return 0;
}
