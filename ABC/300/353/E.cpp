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
constexpr ll MAX = 301010;
constexpr ll MOD = 1e8;
ll arr[MAX], ov;
vector <ll> num;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);

    for(int i = 1;i <= n;i++) {
        auto lb = lower_bound(all(num), MOD - arr[i]);
        if (lb != num.end()) ov += i - (lb - num.begin()) - 1;
        num.push_back(arr[i]);
    }
    ll cnt = n - 1;

    ll result = 0;
    for(int i = 1;i <= n;i++){
        result += (cnt * arr[i]);
    }

    cout << result - (MOD * ov);
    
  
    return 0;
}
