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
ll x, y;
vector <ll> arr;

bool solve(ll cur, ll cx, ll cy){
    if(cur == 3){
        if(cx >= 0 && cy >= 0) return 1;
        return 0;
    }
    if(cx == 0 || cy == 0) return 0;

    ll px, py;
    px = arr[cur] / cy; py = arr[cur] / cx;
    if(arr[cur] % cy) px++; if(arr[cur] % cx) py++;

    bool ret = solve(cur + 1, cx - px, cy);
    ret = max(ret, solve(cur + 1, cx, cy - py));

    return ret;
}

int main() {
    fastio;

    cin >> x >> y;
    for(int i = 0;i < 3;i++) cin >> n, arr.push_back(n);

    while(1){
        if(solve(0, x, y)) {
            cout << "Yes"; return 0;
        }
        if(!next_permutation(all(arr))) break;
    }
    cout << "No";


    return 0;
}
