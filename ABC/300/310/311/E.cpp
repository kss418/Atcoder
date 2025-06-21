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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], arr[3010][3010];
ll result, sum[3010][3010], dp[3010][3010];


int main() {
    fastio;

    ll h, w; cin >> h >> w >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        arr[a[i]][b[i]] = 1;
    }

    for(int i = 1;i <= h;i++){
        for(int j = 1;j <= w;j++){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }

    for(int i = 1;i <= h;i++){
        for(int j = 1;j <= w;j++){
            ll cur = min(dp[i - 1][j], dp[i][j - 1]) - 1;
            cur = max(cur, 0ll);
            
            while(i + cur < h && j + cur < w){
                if(sum[i + cur + 1][j + cur + 1] - sum[i + cur + 1][j - 1] - sum[i - 1][j + cur + 1] + sum[i - 1][j - 1] > 0){
                    break;
                }
                cur++;
            }
            if(arr[i][j]) cur = -1;

            dp[i][j] = cur;
            result += cur + 1;
        }
    }

    cout << result;


    return 0;
}
