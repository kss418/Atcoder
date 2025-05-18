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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result;
vector <ll> arr;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i]; 
    
    ll cnt = 1;
    for(int i = 2;i <= n;i++){
        if(a[i] > a[i - 1]) cnt++;
        else{
            if(cnt != 1) arr.push_back(cnt);
            cnt = 1;
        }
    }
    if(cnt != 1) arr.push_back(cnt);

    for(int i = 1;i < arr.size();i++){
        result += (arr[i] - 1) * (arr[i - 1] - 1);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

