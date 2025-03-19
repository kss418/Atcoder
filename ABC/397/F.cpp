#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
ll a[MAX], cnt[MAX], dp[MAX];
ll pre[MAX], suf[MAX], la[MAX];

template <typename T = ll> // query type
class _prop { // 구간 예외 처리하기
public:
    class node{
    public:
        ll v, len;
        node() : node(MINF){}
        node(ll v) : v(v){}
        
        node operator += (node ot){ // add
            return node();
        }

        operator T(){ // update -> query
            return v;
        }
    };

    class lazy_type{
    public:
        ll v;
        lazy_type() : lazy_type(0){}
        lazy_type(ll v) : v(v){}
    };

    vector<node> seg; ll n;
    vector<lazy_type> lazy;

    node merge(node l, node r){ 
        return { max(l.v, r.v) };
    }

    bool empty(lazy_type lazy){ // prop 시 return 여부 결정
        return !lazy.v;
    }

    void prop(lazy_type& s, lazy_type p){ // lazy -> lazy prop 연산
        s.v += p.v;
    }

    void cal(lazy_type lazy, node& seg){ //lazy로 인한 seg 값 계산
        seg.v += lazy.v;
    }

    void erase(lazy_type& lazy){ // lazy값 초기화
        lazy = 0;
    }

    _prop() {}
    _prop(ll n) {
        this->n = n; 
        seg.resize(4 * n + 1, node()); lazy.resize(4 * n + 1, lazy_type());
    }

    void propagate(ll l, ll r, ll node) {
        if (empty(lazy[node])) return;
        if (l != r) {
            prop(lazy[node * 2], lazy[node]);
            prop(lazy[node * 2 + 1], lazy[node]);
        }
        cal(lazy[node], seg[node]);
        erase(lazy[node]);
    }


    void add(ll st, ll en, ll val) { add(st, en, val, 0, n); }
    void add(ll st, ll en, ll val, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return;
        if (l >= st && r <= en) {
            lazy[node].v += val; propagate(l, r, node);
            return;
        }

        ll mid = (l + r) >> 1;
        add(st, en, val, l, mid, node * 2);
        add(st, en, val, mid + 1, r, node * 2 + 1);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    T query(ll st, ll en) { return query(st, en, 0, n); }
    node query(ll st, ll en, ll l, ll r, ll node = 1) {
        propagate(l, r, node);

        if (st > r || en < l) return _prop::node();
        if (l >= st && r <= en) return seg[node];

        ll mid = (l + r) >> 1;
        return merge(query(st, en, l, mid, node * 2), query(st, en, mid + 1, r, node * 2 + 1));
    }
};

void run(){
    cin >> n; _prop seg(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1]; cnt[a[i]]++;
        if(cnt[a[i]] == 1) pre[i]++;
    }

    memset(cnt, 0, sizeof(cnt));
    for(int i = n;i >= 1;i--){
        suf[i] = suf[i + 1]; cnt[a[i]]++;
        if(cnt[a[i]] == 1) suf[i]++;
    }

    for(int i = 1;i <= n;i++){
        seg.add(la[a[i]], i, 1);
        dp[i] = seg.query(1, i);
        ll now = seg.query(i, i);
        seg.add(i, i, pre[i] - now);
        la[a[i]] = i;
    }

    ll result = 0;
    for(int i = 1;i < n;i++) result = max(result, dp[i] + suf[i + 1]);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
