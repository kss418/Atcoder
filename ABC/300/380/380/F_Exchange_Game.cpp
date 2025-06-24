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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], c[MAX], p[MAX];
vector <ll> num;
map <ll, ll> org;

class node{
public:
    pair<vector<ll>, ll> a, b, c;
    node(){
        a.x.resize(13);
        b.x.resize(13);
        c.x.resize(13);
        a.y = b.y = c.y = 0;
    }

    bool operator <(const node& ot) const{
        if(a.y != ot.a.y) return a.y < ot.a.y;
        else if(b.y != ot.b.y) return b.y < ot.b.y;
        return c.y < ot.c.y;
    }
};
map <node, bool> dp[2];
node st;

void push(pair <vector<ll>, ll>& cur, ll v){
    cur.x[v]++;
    cur.y += p[v];
}

void pop(pair <vector<ll>, ll>& cur, ll v){
    cur.x[v]--;
    cur.y -= p[v];
}

void pass(pair <vector<ll>, ll>& a, pair <vector<ll>, ll>& b, ll v){
    pop(a, v);
    push(b, v);
}

bool chk(pair <vector<ll>, ll>& cur){
    return !cur.y;
}

bool solve(const node& cur, ll t){
    if(dp[t].count(cur)) return dp[t][cur];
    dp[t][cur] = 0;
    node nxt = cur;

    auto cv = t ? cur.b : cur.a;
    if(chk(cv)) return dp[t][cur] = 0;

    for(int i = 1;i <= 12;i++){
        ll now = cv.x[i];
        if(!now) continue;
        
        pass(t ? nxt.b : nxt.a, nxt.c, i);
        dp[t][cur] |= (solve(nxt, t ^ 1) ^ 1);

        for(int j = 1;j < i;j++){
            ll nn = cur.c.x[j];
            if(!nn) continue;

            pass(nxt.c, t ? nxt.b : nxt.a, j);
            dp[t][cur] |= (solve(nxt, t ^ 1) ^ 1);
            pass(t ? nxt.b : nxt.a, nxt.c, j);
        }

        pass(nxt.c, t ? nxt.b : nxt.a, i);
    }

    return dp[t][cur];
}

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i], num.push_back(a[i]);
    for(int i = 1;i <= m;i++) cin >> b[i], num.push_back(b[i]);
    for(int i = 1;i <= k;i++) cin >> c[i], num.push_back(c[i]);
    sort(all(num));

    ll pre = 0, now = 0;
    for(auto& i : num){
        if(pre != i) now++; pre = i;
        org[i] = now;
    }

    p[1] = 1;
    for(int i = 2;i <= 13;i++) p[i] = p[i - 1] * 13;

    for(int i = 1;i <= n;i++) push(st.a, org[a[i]]);
    for(int i = 1;i <= m;i++) push(st.b, org[b[i]]);
    for(int i = 1;i <= k;i++) push(st.c, org[c[i]]);
    
    bool ret = solve(st, 0);
    if(ret) cout << "Takahashi";
    else cout << "Aoki";

    return 0;
}

