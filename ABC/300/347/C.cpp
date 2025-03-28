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
set <ll> d;

int main() {
    fastio;
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t; d.insert((t - 1) % (m + k));
    }

    ll result = 0;
    for (auto& cur : d) {
        ll nxt = (cur + m) % (m + k);
        if (cur >= k) {
            auto lb = d.lower_bound(nxt);
            if (*lb < cur) continue; 
        }
        else {
            auto lb = d.lower_bound(nxt);
            if (lb != d.end()) continue;
            lb = d.lower_bound(0);
            if (*lb < cur) continue;
        }

        result = 1; break;
    }
   
    if (result) cout << "Yes";
    else cout << "No";


    return 0;
}
