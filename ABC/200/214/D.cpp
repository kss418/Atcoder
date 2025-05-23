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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
tll line[MAX];

class _uf { 
public:
    ll n; vector <ll> p, size;
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1); size.resize(n + 1);
        fill(p.begin(), p.end(), -1);
        fill(size.begin(), size.end(), 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a < b) swap(a, b);
        p[b] = a, size[a] += size[b];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};


int main() {
    fastio;

    cin >> n;
    for(int i = 1;i < n;i++) {
        ll u, v, w; cin >> u >> v >> w;
        line[i] = {w, u, v};
    }
    sort(line + 1, line + n); _uf uf(n);

    ll result = 0;
    for(int i = 1;i < n;i++){
        auto[c, l, r] = line[i];
        l = uf.find(l); r = uf.find(r);
        result += c * uf.size[l] * uf.size[r];
        uf.merge(l, r);
    }

    cout << result;
    

    return 0;
}
