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
vector <ll> a, b;
ll mod[4] = { 1000000007, 998244353, 922337203685471, 1000000009 };
ll key[4] = {29, 31, 2, 26};

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

class _hash { // 0-based index
public:
    ll n, mod, key;
    vector <ll> h, si; _pow pow;
    map <ll, bool> cnt;

    _hash(){}

    _hash(ll n, ll mod, ll key = 2) {
        this->n = n;
        this->mod = mod; this->key = key;
        h.resize(n + 1, 0);
        si.resize(n + 1, 0);
    }

    ll mo(ll n) {
        if (n % mod >= 0) return n % mod;
        else return (n % mod) + mod;
    }

    void init(vector <ll>& arr) {
        h[0] = pow.ret(key, arr[0], mod);
        cnt[arr[0]] = 1; si[0] = 1;
        for (int i = 1; i < n; i++) {
            if(cnt.find(arr[i]) == cnt.end()) h[i] = mo(h[i - 1] + pow.ret(key, arr[i], mod));
            else h[i] = h[i - 1];
            cnt[arr[i]] = 1; si[i] = cnt.size();
        }
    }

    ll ret(ll a) {
        return mo(h[a]);
    }
};

int main() {
    fastio;

    cin >> n; _hash ha[4], hb[4];
    for (int i = 1;i <= n;i++) cin >> k, a.push_back(k);
    for (int i = 1;i <= n;i++) cin >> k, b.push_back(k);

    for(int i = 0;i < 4;i++){
        ha[i] = {n, mod[i], key[i]};
        hb[i] = {n, mod[i], key[i]};
        ha[i].init(a); hb[i].init(b);
    }

    cin >> m; while(m--){
        ll l, r; cin >> l >> r; l--, r--;
        ll flag = 1;
        for(int i = 0;i < 4;i++){
            if(ha[i].si[l] != hb[i].si[r]) flag = 0;
            if(ha[i].ret(l) != hb[i].ret(r)) flag = 0;
        }

        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    
    
    return 0;
}
