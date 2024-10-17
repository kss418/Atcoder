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
ll a[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

int main() {
    fastio;

    cin >> n >> m; 
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; pq.push(a[i]);
        m -= a[i];
    }
    if(m) pq.push(m);

    ll result = 0;
    while(pq.size() >= 2){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();

        result += a + b;
        pq.push(a + b);
    }

    cout << result;

    
    return 0;
}
