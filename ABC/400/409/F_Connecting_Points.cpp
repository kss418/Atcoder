#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 1515; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[2 * MAX];

class node{
public:
    ll s, e, c;
    bool operator > (const node& ot) const{
        return c > ot.c;
    }
};
priority_queue <node, vector<node>, greater<node>> pq;

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
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

void run(){
    cin >> n >> m; ll cnt = n, num = n; 
    _uf uf(2 * MAX);

    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
    }

    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            ll d = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
            pq.push({i, j, d});
        }
    }

    while(m--){
        ll op; cin >> op;
        if(op == 1){
            ll x, y; cin >> x >> y;
            a[++cnt] = {x, y}; num++;
            for(int i = 1;i < cnt;i++){
                ll d = abs(a[i].x - a[cnt].x) + abs(a[i].y - a[cnt].y);
                pq.push({i, cnt, d});
            }
        }
        else if(op == 2){
            if(num == 1) cout << "-1\n";
            else{
                ll now = -1;
                while(!pq.empty()){
                    auto [s, e, c] = pq.top(); pq.pop();
                    if(uf.same(s, e)) continue;
                    uf.merge(s, e); now = c; 
                    num--; break;
                }

                while(!pq.empty()){
                    auto [s, e, c] = pq.top();
                    if(c != now) break; pq.pop();
                    if(uf.same(s, e)) continue;
                    uf.merge(s, e); num--;
                }

                cout << now << "\n";
            }
        }
        else{
            ll a, b; cin >> a >> b;
            if(uf.same(a, b)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

