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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], num[MAX];

void run(){
    cin >> n >> m; ll cnt = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        num[a[i]]++;
        if(num[a[i]] == 1) cnt++;
    }

    if(cnt != m){
        cout << 0; return;
    }

    for(int i = n;i >= 1;i--){
        num[a[i]]--;
        if(!num[a[i]]) cnt--;

        if(cnt != m){
            cout << n - i + 1; return;
        }
    }

    cout << n;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

