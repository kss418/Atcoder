#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX];

class _pow {
public:
	_pow() {}

	ll ret(ll a, ll b){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a;
            a *= a; b >>= 1;
        }      
        return ret;
    }

	ll ret(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
};

bool use[MAX];
ll result[MAX];

int main() {
    fastio;

    cin >> n >> m; _pow pow;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++){
        if(use[i]) continue;
        vector <ll> cycle;
        ll nxt = i;

        while(!use[nxt]){
            use[nxt] = 1;
            cycle.push_back(nxt);
            nxt = a[nxt];
        }

        ll shift = pow.ret(2, m, cycle.size());
        for(int j = 0;j < cycle.size();j++){
            result[cycle[j]] = cycle[(j + shift) % cycle.size()];
        }
    }

    for(int i = 1;i <= n;i++) cout << result[i] << " ";


    return 0;
}
