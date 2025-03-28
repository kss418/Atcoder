#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result;
vector <ll> d[2][2];
pll a[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    for(int i = n;i >= 1;i--){
        bool now = (a[i].x + a[i].y) % 2;
        ll d1 = a[i].x + a[i].y, d2 = a[i].x - a[i].y;
        d[now][0].push_back(d1); d[now][1].push_back(d2);
    }

    for(int i = 0;i <= 1;i++){
        for(int j = 0;j <= 1;j++) {
            sort(all(d[i][j]));
            reverse(all(d[i][j]));
        }
    }

    for(int i = 0;i <= 1;i++){
        for(int j = 0;j <= 1;j++){
            ll cnt = 0, sum = 0;
            for(auto& k : d[i][j]){
                result += sum - cnt * k;
                cnt++; sum += k;
            }
        }
    }

    cout << (result >> 1ll);

     
    return 0;
}
