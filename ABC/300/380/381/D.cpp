#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], use[MAX], num[MAX];

ll ret(ll st){
    ll ret = 0, s = st;
    memset(use, 0, sizeof(use));

    for(int i = st;i <= n;i += 2){
        if(!num[i]) {
            while(s <= i) use[a[s]] = 0, s += 2;
        }
        else{
            if(use[a[i]]){
                while(s < i){
                    use[a[s]] = 0; s += 2;
                    if(a[s - 2] == a[i]) break;
                }
            }

            ret = max(ret, i - s + 2);
            use[a[i]] = 1;
        }
    }

    return ret;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        if(a[i] == a[i + 1]) num[i] = 1;
    }

    ll result = max(ret(1), ret(2));
    cout << result;


    return 0;
}

