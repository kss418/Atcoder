#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
constexpr ll MOD = 1e9 + 7;
pll arr[MAX];
ll diff[MAX];

int main() {
    fastio;

    for (int i = 0; i < 3; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < 3; i++) {
        ll dx = (arr[i].first - arr[(i + 1) % 3].first);
        ll dy = (arr[i].second - arr[(i + 1) % 3].second);
        diff[i] = (dx * dx) + (dy * dy);
    }
    sort(diff, diff + 3);

    if (diff[2] == diff[0] + diff[1]) cout << "Yes";
    else cout << "No";

  
    

    return 0;
}
