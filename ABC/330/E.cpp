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
ll a[MAX], cnt[MAX];
set <ll> num;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] < MAX) cnt[a[i]]++;
    }

    for(int i = 0;i < MAX;i++) {
        if(!cnt[i]) num.insert(i);
    }

    while(m--){
        ll idx, v; cin >> idx >> v;
        if(a[idx] < MAX) {
            if(!--cnt[a[idx]]) num.insert(a[idx]);
        }

        a[idx] = v;
        if(v < MAX) {
            if(++cnt[v] == 1) num.erase(v);
        }

        cout << *num.begin() << '\n';
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

