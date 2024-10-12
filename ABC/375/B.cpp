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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll x[MAX], y[MAX];

long double dist(ll x1, ll y1, ll x2, ll y2){
    ll dx = x1 - x2, dy = y1 - y2;
    ll pow = dx * dx + dy * dy;
    return sqrt(pow);
}

int main() {
    fastio;

    cin >> n;

    long double result = 0;
    for(int i = 1;i <= n + 1;i++) {
        cin >> x[i] >> y[i];
        result += dist(x[i - 1], y[i - 1], x[i], y[i]);
    }

    cout.precision(15);
    cout << result;
    

    return 0;
}
