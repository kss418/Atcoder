#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 81;
constexpr ll MOD = 998244353;
pll arr[MAX];
ll dp[MAX][MAX][10101];

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        ll a, b;
        cin >> a >> b;
        arr[i] = {a,b};
    }
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for(int cur = 1;cur <= n;cur++){
        for(int cnt = 0;cnt <= cur;cnt++){
            for(int j = 0;j <= k;j++){
                dp[cur][cnt][j] = min(dp[cur][cnt][j], dp[cur - 1][cnt][j]);
                if(j >= arr[cur].y && cnt) dp[cur][cnt][j] = min(dp[cur][cnt][j], dp[cur - 1][cnt - 1][j - arr[cur].y] + arr[cur].x);
            }
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= k;j++){
            if(dp[n][i][j] > m) continue;
            result = max<ll>(result, i);
        }
    }

    cout << min(result + 1, n);


    return 0;
}
