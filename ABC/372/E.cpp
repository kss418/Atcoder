#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;

set <ll, greater<ll>> arr[MAX];
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
        p[b] = a; size[a] += size[b];
        while (!arr[b].empty()) {
            auto it = arr[b].begin();
            arr[a].insert(*it);
            arr[b].erase(it);
        }
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};

int main() {
    fastio;
    
    cin >> n >> m;
    _uf uf(n);
    for (int i = 1; i <= n; i++) arr[i].insert(i);

    while (m--) {
        ll num, a, b;
        cin >> num >> a >> b;
        if (num == 1) uf.merge(a, b);
        else {
            a = uf.find(a);
            if (arr[a].size() < b) cout << -1 << "\n";
            else {
                auto it = arr[a].begin();
                for (int i = 1; i < b; i++) it++;
                cout << *it << "\n";
            }
        }
    }
  


    return 0;
}
