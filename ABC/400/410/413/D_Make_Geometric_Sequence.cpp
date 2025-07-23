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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt;

void run(){
    cin >> n; cnt = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1, [](ll& l, ll& r){
        return abs(l) < abs(r);
    });

    bool flag = 1;
    for(int i = 1;i < n;i++){
        if(abs(a[i]) != abs(a[i + 1])) flag = 0;
        cnt += (a[i] < 0 ? -1 : 1);
    }
    cnt += (a[n] < 0 ? -1 : 1);
    if(flag && abs(cnt) <= 1){ cout << "Yes\n"; return; } 

    flag = 1;
    for(int i = 1;i < n - 1;i++){
        if(a[i + 1] * a[i + 1] != a[i] * a[i + 2]) flag = 0;
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

