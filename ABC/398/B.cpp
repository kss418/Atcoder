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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[22];

void run(){
    for(int i = 1;i <= 7;i++) cin >> a[i], cnt[a[i]]++;
    ll result = 0;
    for(int i = 1;i <= 13;i++){
        for(int j = 1;j <= 13;j++){
            if(i == j) continue;
            if(cnt[i] >= 2 && cnt[j] >= 3) result = 1;
        }
    }

    cout << (result ? "Yes" : "No");
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

