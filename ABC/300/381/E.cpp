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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> idx[3];

ll lb(const vector<ll>& v, ll x){
    return lower_bound(all(v), x) - v.begin();
}

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r, s, e;
    _bs(T l, T r, T s, T e) {
        this->l = l; this->r = r;
        this->s = s; this->e = e;
    }

    bool f(T cur) {
        if(!cur){
            ll cnt = lb(idx[0], s);
            if(cnt >= idx[0].size()) return 0;
            return idx[0][cnt] <= e;
        }

        ll cnt = lb(idx[1], s);
        if(cnt + cur - 1 >= idx[1].size()) return 0;

        cnt = lb(idx[0], idx[1][cnt + cur - 1]);
        if(cnt >= idx[0].size()) return 0;

        cnt = lb(idx[2], idx[0][cnt]);
        if(cnt + cur - 1 >= idx[2].size()) return 0;
        return idx[2][cnt + cur - 1] <= e; 
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};


int main() {
    fastio;

    cin >> n >> m >> s;
    for(int i = 0;i < n;i++){
        if(s[i] == '/') idx[0].push_back(i);
        else idx[s[i] - '0'].push_back(i);
    }

    while(m--){
        ll l, r; cin >> l >> r;
        _bs<ll> bs(-1, n, l - 1, r - 1);
        ll ret = bs.ret();
        cout << (ret == -1 ? 0 : 2 * ret + 1) << "\n";
    }
    
     
    return 0;
}
