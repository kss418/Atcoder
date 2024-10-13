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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
long double a[MAX], b[MAX];


int main() {
    fastio;

    cin >> n; long double s = 0.0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        s += a[i] / b[i];
    }

    long double result = 0;
    s /= (long double)2;
    for(int i = 1;i <= n;i++){
        if(s >= a[i] / b[i]) {
            s -= a[i] / b[i];
            result += a[i];
        }
        else{
            long double t = a[i] / b[i];
            long double per = s / t;

            result += a[i] * per; break;
        }
    }

    cout.precision(15);
    cout << result;
    

    return 0;
}
