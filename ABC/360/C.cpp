#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll a[MAX], w[MAX];
vector <ll> arr[MAX];

int main() {
    fastio;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> w[i]; arr[a[i]].push_back(w[i]);
    }

    ll result = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i].size() <= 1) continue;
        sort(arr[i].begin(), arr[i].end());
        
        ll sum = 0;
        for (int j = 0; j < arr[i].size() - 1; j++) sum += arr[i][j];

        result += sum;
    }

    cout << result;


    return 0;
}
