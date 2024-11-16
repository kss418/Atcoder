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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cnt[MAX], num[MAX];
ll l[MAX], r[MAX];

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
        l[a] = min(l[a], l[b]);
        r[a] = max(r[a], r[b]);
    }

    ll size(ll num){
        return si[find(num)];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};

int main() {
    fastio;

    cin >> n >> m; _uf uf(n + 1);
    for(int i = 1;i <= n;i++) {
        num[i] = l[i] = r[i] = i;
        cnt[i] = 1;
    }

    while(m--){
        ll com; cin >> com;
        if(com == 1){
            ll idx, val; cin >> idx >> val;
            ll cur = uf.find(idx);
            cnt[num[cur]] -= uf.size(idx);
            cnt[val] += uf.size(idx);

            if(num[uf.find(l[cur] - 1)] == val) uf.merge(l[cur] - 1, cur);
            if(num[uf.find(r[cur] + 1)] == val) uf.merge(r[cur] + 1, cur);
            num[uf.find(idx)] = val;
        }
        else{
            ll idx; cin >> idx;
            cout << cnt[idx] << "\n";
        }
    }


    return 0;
}

