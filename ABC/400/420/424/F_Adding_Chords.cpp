#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class _seg { // 구간 예외 처리하기
public:
    ll n, sz;
    class node{
    public:
        ll mx, mn;
        node() : node(MINF, INF){} // identity
        node(ll mx, ll mn) : mx(mx), mn(mn) {}

        operator pll(){ // query
            return {mx, mn};
        }
    }; vector <node> seg;

    _seg(){}
    _seg(ll n) : n(n){ 
        sz = 1; while(sz < n + 1) sz <<= 1ll;
        seg.assign(2 * sz, node());
    }

    node merge(node l, node r){
        return{
            max(l.mx, r.mx),
            min(l.mn, r.mn)
        };
    }

    node query(ll st, ll en) {
        st = max(0ll, st); en = min(n, en);
        if(st > en) return node();

        node l = node(), r = node();
        st += sz; en += sz;
        while(st <= en){
            if(st & 1) l = merge(l, seg[st++]);
            if(!(en & 1)) r = merge(seg[en--], r);
            st >>= 1; en >>= 1; 
        }

        return merge(l, r);
    }

    void set(ll idx, node val){
        if(idx < 0 || idx > n) return;
        ll p = idx + sz;
        seg[p] = merge(seg[p], val);
        for(p >>= 1ll; p; p >>= 1){
            seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
        }
    }

    void clear(){ fill(all(seg), node()); }
}; _seg seg;

void run(){
    cin >> n >> m; seg = {2 * n + 1};   

    while(m--){
        ll s, e; cin >> s >> e;
        pll q = seg.query(s + 1, e - 1);

        if(q.x >= e || q.y <= s) cout << "No" << "\n";
        else{
            cout << "Yes" << "\n";
            seg.set(s, {e, e}); seg.set(e, {s, s});
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}