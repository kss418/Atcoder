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
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
deque <ll> cy, cx, oy, ox;

ll solve(deque <ll>& v, ll cur){
    ll ret = 0, use[2] = {1, 1};
    while(v.size() >= 2 && v.back() - v.front() > cur){
        if(use[0] < use[1]){
            ll diff = v[1] - v[0]; 
            ret += diff * use[0]; v.pop_front();
            if(v.back() - v.front() < cur){
                v.push_front(v.back() - cur);
                ret -= (v[1] - v[0]) * use[0];
            }
            use[0]++;
        }
        else{
            ll diff = v.back() - v[v.size() - 2];
            ret += diff * use[1]; v.pop_back();
            if(v.back() - v.front() < cur){
                v.push_back(v.front() + cur);
                ret -= (v.back() - v[v.size() - 2]) * use[1];
            }
            use[1]++;
        }
    }
    
    return ret;
}

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        cy = oy; cx = ox;
        ll ret = solve(cy, cur) + solve(cx, cur);
        
        return ret > m;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m; _bs <ll> bs(0, 1e10);
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        oy.push_back(a[i].x);
        ox.push_back(a[i].y);
    }
    sort(all(ox)); sort(all(oy));
    
    cout << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

