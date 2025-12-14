#include <bits/stdc++.h>
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
ll a[MAX];

using node = pair<f128, ll>;
priority_queue <node> pq;
vector <node> arr;

void run(){
    cin >> n >> m >> k; arr.clear();
    for(int i = 1;i <= n;i++) cin >> a[i], pq.push({a[i], 1});

    while(m){
        auto [cn, cc] = pq.top(); pq.pop();
        ll mn = min(m, cc);
        pq.push({cn / (ld)2, 2 * mn});
        if(cc - mn > 0) pq.push({cn, cc - mn});
        m -= mn; 
    }

    while(!pq.empty()){
        arr.push_back(pq.top()); pq.pop();
    }

    ll now = 0;
    for(auto& [cn, cc] : arr){
        now += cc;
        if(now >= k){
            cout.precision(30);
            cout << (ld)cn << "\n";
            break;
        }
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}