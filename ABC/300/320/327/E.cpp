#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ld dp[MAX][MAX], result = MINF;
ld mul[MAX], sum[MAX]; ll a[MAX];

void init(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) dp[i][j] = -1e12;
    }
}

ld cal(ll num, ll cnt){
    return (ld)num * mul[cnt];
}

ld solve(ll cur, ll cnt){
    ld& ret = dp[cur][cnt];
    if(ret > -1e12 + 1) return ret; ret = -1e11;
    if(!cur || !cnt) return ret = 0;

    ret = max(ret, solve(cur - 1, cnt));
    ret = max(ret, solve(cur - 1, cnt - 1) + cal(a[cur], cnt));

    return ret;
}

void run(){
    cin >> n; init();
    for(int i = 1;i <= n;i++) cin >> a[i];
    reverse(a + 1, a + n + 1);

    mul[1] = sum[1] = 1;
    for(int i = 2;i <= n;i++){
        mul[i] = mul[i - 1] * 9 / (ld)10;
        sum[i] = sum[i - 1] + mul[i];
    }

    for(int i = 1;i <= n;i++){
        ld now = solve(n, i) / sum[i];
        result = max(result, now - ((ld)1200 / sqrtl(i)));
    }

    cout.precision(20);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
