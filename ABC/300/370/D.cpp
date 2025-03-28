#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 401010;
constexpr ll MOD = 1e9 + 7;
vector<set <ll>> x, y, mx, my;

int main() {
    fastio;

    cin >> n >> m >> k;
    y.resize(n + 1); x.resize(m + 1);
    my.resize(n + 1); mx.resize(m + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            y[i].insert(j); my[i].insert(-j);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            x[i].insert(j); mx[i].insert(-j);
        }
    }

    ll result = n * m;
    while (k--) {
        ll cx, cy;
        cin >> cy >> cx;
        if (x[cx].count(cy)) {
            y[cy].erase(cx); my[cy].erase(-cx);
            x[cx].erase(cy); mx[cx].erase(-cy);
            result--;
        }
        else {
            auto uy = x[cx].upper_bound(cy);
            if (uy != x[cx].end()) {
                ll val = *uy;
                x[cx].erase(val); mx[cx].erase(-val);
                y[val].erase(cx); my[val].erase(-cx);
                result--;
            }

            auto ux = y[cy].upper_bound(cx);
            if (ux != y[cy].end()) {
                ll val = *ux;
                y[cy].erase(val); my[cy].erase(-val);
                x[val].erase(cy); mx[val].erase(-cy);
                result--;
            }

            auto lx = my[cy].upper_bound(-cx);
            if (lx != my[cy].end()) {
                ll val = *lx;
                y[cy].erase(-val); my[cy].erase(val);
                x[-val].erase(cy); mx[-val].erase(-cy);
                result--;
            }

            auto ly = mx[cx].upper_bound(-cy);
            if (ly != mx[cx].end()) {
                ll val = *ly;
                x[cx].erase(-val); mx[cx].erase(val);
                y[-val].erase(cx); my[-val].erase(-cx);
                result--;
            }
        }
    }

    cout << result;




    return 0;
}
