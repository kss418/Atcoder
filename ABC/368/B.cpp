#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
ll cnt;
deque <ll> arr;

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> k, arr.push_back(k);
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    while (1) {
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        while (!arr.empty() && arr.back() == 0) arr.pop_back();
        if (arr.size() <= 1) break;
        ++cnt;

        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        if(arr[0] >= 1) arr[0]--; if (arr.size() >= 2 && arr[1] >= 1) arr[1]--;
    }

    cout << cnt;
    
    return 0;
}
