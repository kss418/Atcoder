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
ll r[MAX], c[MAX], x[MAX];
map <ll, ll> rm, cm;
map <pll, ll> arr;

int main() {
    fastio;

    cin >> n; 
    for(int i = 1;i <= n;i++) {
        cin >> r[i] >> c[i] >> x[i];
        rm[r[i]] += x[i]; cm[c[i]] += x[i];
        arr[{r[i], c[i]}] = x[i];
    }

    ll result = 0, idx = 0, mx = 0;
    for(auto &i : rm){
        if(i.y > mx) idx = i.x, mx = i.y;
    }
    for(auto &i : cm){
        result = max(i.y + mx - arr[{idx, i.x}], result);
    }

    idx = 0, mx = 0;
    for(auto &i : cm){
        if(i.y > mx) idx = i.x, mx = i.y;
    }
    for(auto &i : rm){
        result = max(i.y + mx - arr[{i.x, idx}], result);
    }

    cout << result;


    return 0;
}
