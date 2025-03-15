#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], pre[MAX], suf[MAX], cnt[MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        if(!cnt[a[i]]) pre[i] = pre[i - 1] + 1;
        else pre[i] = pre[i - 1];
        cnt[a[i]] = 1;
    }

    memset(cnt, 0, sizeof(cnt));
    for(int i = n;i >= 1;i--){
        if(!cnt[a[i]]) suf[i] = suf[i + 1] + 1;
        else suf[i] = suf[i + 1];
        cnt[a[i]] = 1;
    }

    ll result = 0;
    for(int i = 1;i < n;i++){
        result = max(result, pre[i] + suf[i + 1]);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

