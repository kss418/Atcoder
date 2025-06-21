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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 601010;
constexpr ll MOD = 998244353;

class _pow {
public:
	_pow() {}

	ll ret(ll a, ll p) {
		if (!p) return 1;
		if (p == 1) return a;

		ll cur = ret(a, p / 2);
		cur = cur * cur;
		if (p % 2 == 0) return cur;
		return cur * a;
	}

	ll ret(ll a, ll p, ll mod) {
		if (!p) return 1;
		if (p == 1) return a % mod;

		ll cur = ret(a, p / 2, mod);
		cur = cur * cur % mod;
		if (p % 2 == 0) return cur % mod;
		return (cur * a) % mod;
	}
};
deque <char> st;

int main() {
    fastio;

    ll q; cin >> q;
    ll result = 1;
    st.push_back('1');
    _pow pow;

    while(q--){
        ll com, x; cin >> com;
        if(com == 1){
            cin >> x;
            st.push_back(x + '0');
            result *= 10; result += x;
            result %= MOD;
        }
        else if(com == 2){
            ll fr = st.front() - '0';
            st.pop_front();
            result -= (pow.ret(10, st.size(), MOD) * fr) % MOD;
            result = (result + MOD) % MOD;
        }
        else cout << (result + MOD) % MOD << "\n";
    }


    return 0;
}
