#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class _sa{
public:
    ll n, d, k = 0; vector <ll> arr;
    vector <ll> sa, pos, tmp, lcp;
    bool cmp(ll a, ll b){
        if(pos[a] != pos[b]) return pos[a] < pos[b];
        a += d; b += d;
        if(a < n && b < n) return pos[a] < pos[b];
        return a > b;
    }  

    void init(string& s){ for(auto& i : s) arr.push_back(i); init(); }
    void init(vector <ll>& a){ this->arr = a; init(); }

    void init(){
        this->n = arr.size(); tmp.resize(n);
        sa.resize(n); pos.resize(n);
        iota(all(sa), 0); lcp.resize(n);
        for(int i = 0;i < n;i++) pos[i] = arr[i];
        get_sa(); get_lcp();
    }

    void get_sa(){
        for(d = 1; ;d <<= 1){
            sort(all(sa), [this](ll a, ll b) { return cmp(a, b); }); tmp[0] = 0;
            for(int i = 0;i < n - 1;i++) {
                tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
            }
            for(int i = 0;i < n;i++) pos[sa[i]] = tmp[i];
            if(tmp[n - 1] == n - 1) break;
        }
    }

    void get_lcp(){
        for(int cur = 0;cur < n;cur++){
            k = max(k - 1, 0ll);
            if(pos[cur] == n - 1) continue;
            ll nxt = sa[pos[cur] + 1];
            while(arr[cur + k] == arr[nxt + k]) k++;
            lcp[pos[cur]] = k;
        }
    }

    _sa(string& s){ init(s); }
    _sa(vector <ll>& a) { init(a); }
    _sa() {}
}; _sa sa;

ll ub(const string& st, ll l, ll r){
    if(l == r) return l;
    ll mid = (l + r) / 2;
    ll ai = sa.sa[mid], bi = 0;

    while(ai < s.size() && bi < st.size()){
        if(s[ai] < st[bi]) return ub(st, mid + 1, r);
        if(s[ai] > st[bi]) return ub(st, l, mid);
        ai++; bi++;
    }

    return ub(st, mid + 1, r);
}

ll lb(const string& st, ll l, ll r){
    if(l == r) return l;
    ll mid = (l + r) / 2;
    ll ai = sa.sa[mid], bi = 0;

    while(ai < s.size() && bi < st.size()){
        if(s[ai] < st[bi]) return lb(st, mid + 1, r);
        if(s[ai] > st[bi]) return lb(st, l, mid);
        ai++; bi++;
    }

    if(bi == st.size()) return lb(st, l, mid);
    return lb(st, mid + 1, r);
}

ll solve(const string& st){
    return ub(st, 0, s.size()) - lb(st, 0, s.size());
}

void run(){
    cin >> s >> n; sa.init(s);
    while(n--){
        string st; cin >> st;
        cout << solve(st) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}