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
ll n, m, k; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
vector <ll> arr[3];
ll sum[MAX];

class _ts { // 0-based index
public:
    ll l, r;
    _ts(ll l, ll r) {
        this->l = l; this->r = r;
    }

    ll f(ll cur) {
        ll use = 0, pick = m - cur, ret = 0;
        if(cur >= 1) use = sum[cur - 1];
        ll a = 0, b = 0;

        for(int i = 0;i < pick;i++){
            if(a < arr[0].size() && b < arr[1].size()){
                if(use){
                    if(arr[0][a] >= arr[1][b]) ret += arr[0][a++];
                    else ret += arr[1][b++], use--;
                }
                else ret += arr[0][a++];
            }
            else if(a < arr[0].size()) ret += arr[0][a++];
            else if(b < arr[1].size() && use) ret += arr[1][b++], use--;
        }

       return ret;
    }

    ll ret() {
        while (r - l > 3) {
            ll st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) < f(en)) l = st;
            else r = en;
        }

        ll result = -INF;
        for(ll cur = l; cur <= r;cur++) result = max(result, f(cur));

        return result;
    }
};

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        ll t, x; cin >> t >> x;
        arr[t].push_back(x);
    }
    for(int i = 0;i < 3;i++) sort(all(arr[i])), reverse(all(arr[i]));

    if(!arr[2].empty()) sum[0] = arr[2][0];
    for(int i = 1;i < arr[2].size();i++) sum[i] = sum[i - 1] + arr[2][i];

    _ts ts(0, arr[2].size());
    cout << ts.ret();


    return 0;
}
