#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;

class _bs { // 0-based index
public:
    ll l, r, num;
    _bs(ll l, ll r, ll num) {
        this->l = l; this->r = r;
        this->num = num;
    }

    ll f(ll cur) {
        ll ret = 1;
        for (int i = 1; i <= num; i++) {
            double tmp = ret;
            tmp *= cur;
            if (tmp > 2e18) return 2e18;
            ret *= cur;
        }

        return ret;
    }

    ll ret() {
        ll lo = l, hi = r, mid = -1;
        while (hi >= lo) {
            mid = (hi + lo) >> 1;
            if (f(mid) <= n) lo = mid + 1;
            else hi = mid - 1;
        }

        return hi;
    }
};

vector <ll> pf(ll cur) {
    vector <ll> ret;
    for (ll i = 2; i * i <= cur; i++) {
        while (cur % i == 0) {
            cur /= i;
            ret.push_back(i);
        }
    }

    if (cur != 1) ret.push_back(cur);
    return ret;
}

int main() {
    fastio;

    cin >> n;
    
    ll result = 0;
    for (ll b = 2; b < 60; b++) {
        ll l = 2, r = 2e9;
        _bs bs(l, r, b);
        ll a = bs.ret();

        vector <ll> p = pf(b);
        bool same = 0;

        for (ll i = 1; i < p.size(); i++) {
            if (p[i - 1] != p[i]) continue;
            same = 1; break;
        }

        if (same) continue;
        if (p.size() % 2) result += a - 1;
        else result -= a - 1;
    }

    cout << result + 1;


    return 0;
}
