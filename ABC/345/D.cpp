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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX]; vector <ll> seq;
ll arr[MAX], rot[MAX];

ll solve(){
    for(auto& i : seq){
        pll now = a[i]; ll idx = 1;
        if(rot[i]) swap(now.x, now.y);

        for(int i = 2;i <= k;i++){
            if(arr[i] < arr[idx]) idx = i;
        }

        if(idx + now.x > k + 1) return 0;

        ll pre = arr[idx];
        for(int j = idx;j < idx + now.x;j++){
            if(pre != arr[j]) return 0;
            arr[j] += now.y;
        }

        idx += now.x;
    }

    for(int i = 1;i <= k;i++){
        if(arr[i] != m) return 0;
    }

    return 1;
}

ll per(){
    while(1){
        ll sz = seq.size();
        for(int i = 0;i < (1ll << sz);i++){
            for(int j = 0;j < sz;j++){
                ll now = 1ll << j;
                rot[seq[j]] = (now & i) ? 1 : 0;
            }

            memset(arr, 0, sizeof(arr)); 
            if(solve()) return 1;
        }

        if(!next_permutation(all(seq))) break;
    }

    return 0;
}

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) cin >> a[i].x >> a[i].y;

    for(int i = 1;i < (1ll << n);i++){
        seq.clear();
        for(int j = 0;j < n;j++){
            ll now = 1ll << j;
            if(now & i) seq.push_back(j);
        }

        ll ret = per();
        if(ret) { cout << "Yes"; return 0; } 
    }

    cout << "No";

     
    return 0;
}
