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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
vector <ll> arr, vec;

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

ll solve(ll cur){
    ll ret = 0; _pow pow; string st;
    while(cur){
        ll now = cur % 10;
        st.push_back(now + '0'); cur /= 10;
    }
    reverse(all(st));

    for(int i = 1;i < st.size();i++){
        ret += pow.ret(st[0] - '0', st.size() - i - 1) * min<ll>(st[0] - '0', st[i] - '0');
        if(st[i] >= st[0]) break;
        if(i == st.size() - 1){ ret++; break; }
    }

    for(int i = 0;i < st.size() - 1;i++){
        ll mx = (i ? 9 : st[0] - '0' - 1);
        for(int j = 1;j <= mx;j++) ret += pow.ret(j, st.size() - i - 1);
    }

    return ret;
}

void run(){
    cin >> n >> m;
    cout << solve(m) - solve(n - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
