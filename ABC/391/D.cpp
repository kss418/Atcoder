#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
vector <pll> arr[MAX];
ll er[MAX];

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        arr[a[i].x].push_back({a[i].y, i});
    }

    ll mn = INF; memset(er, 0x3f, sizeof(er));
    for(int i = 1;i <= m;i++) {
        sort(all(arr[i]));
        mn = min<ll>(mn, arr[i].size());
    }

    for(int i = 0;i < mn;i++){
        ll now = 0;
        for(int j = 1;j <= m;j++) now = max(now, arr[j][i].x);
        for(int j = 1;j <= m;j++) er[arr[j][i].y] = now;
    }

    cin >> k;
    while(k--){
        ll num, t; cin >> t >> num;
        cout << (er[num] > t ? "Yes" : "No") << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

