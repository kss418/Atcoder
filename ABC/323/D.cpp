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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
map <ll, ll> cnt;
set <ll> num;
ll result;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        cnt[a[i].x] = a[i].y;
        num.insert(a[i].x);
    }

    while(!num.empty()){
        auto now = *num.begin();
        num.erase(num.begin());
        ll sz = cnt[now];
        ll same = sz / 2;

        if(same) {
            cnt[2 * now] += same;
            num.insert(2 * now);
        }
        result += sz % 2;
    }


    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
