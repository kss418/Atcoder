#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
ll cnt[1010101];
set <ll> num;


int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cin >> k;
            num.insert(k);
            cnt[k]++;
        }
        else if (n == 2) {
            cin >> k;
            cnt[k]--;
            if (!cnt[k]) num.erase(k);
        }
        else {
            cout << num.size() << '\n';
        }
    }

  
    return 0;
}
