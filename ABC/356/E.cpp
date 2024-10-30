#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX], cnt[1010101];

int main() {
    fastio;


    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; cnt[a[i]]++;
    }

    ll result = 0;
    for(int i = 1;i < 1010101;i++) {
        result -= cnt[i] * (cnt[i] + 1) / 2;
        cnt[i] += cnt[i - 1];
    }

    for(int now = 1;now < 1010101;now++){
        for(int down = 1;down * now < 1010101;down++){
            ll lo = down * now, hi = down * (now + 1) - 1;
            ll num = cnt[down] - cnt[down - 1];
            hi = min<ll>(hi, 1010100);
            result += (cnt[hi] - cnt[lo - 1]) * now * num;
        }
    }

    cout << result;
    

    return 0;
}

