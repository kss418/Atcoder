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
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
ll a[10], b[10], c[10], d[10];

long double dist(ll cx, ll cy, ll nx, ll ny){
    ll dx = cx - nx;
    ll dy = cy - ny;
    ll p = dx * dx + dy * dy;
    long double ret = sqrt(p);

    return ret;
}

int main() {
    fastio;
    long double s, t;

    cin >> n >> s >> t;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector <ll> arr;
    for(int i = 0;i < n;i++) arr.push_back(i);

    long double result = 1e9;
    while(1){
        for(int i = 0;i < (1ll << n);i++){
            ll cx = 0, cy = 0; long double cur = 0;
            for(int j = 0;j < n;j++){
                ll num = arr[j];
                ll st = i & (1ll << num);
                if(st){
                    cur += dist(cx, cy, a[num], b[num]) / s;
                    cx = c[num]; cy = d[num];
                }
                else{
                    cur += dist(cx, cy, c[num], d[num]) / s;
                    cx = a[num]; cy = b[num];
                }
                cur += dist(a[num], b[num], c[num], d[num]) / t;
            }

            result = min(result, cur);
        }

        if(!next_permutation(all(arr))) break;
    }
    
    cout.precision(18);
    cout << result;


    return 0;
}
