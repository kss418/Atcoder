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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
pll ry = {MINF, MINF}, rx = {MINF, MINF};
vector <ll> vx[2], vy[2];
vector <ll> sx[2], sy[2];
vector <pll> tx[2], ty[2];
vector <char> result;

void init(vector <ll> &v, vector <ll> &s, vector <pll>& t){
    ll sz = v.size();
    if(v.empty()) s.push_back(0);
    for(int i = 0;i < (1ll << sz);i++){
        ll now = 0;
        for(int j = 0;j < sz;j++){
            now += v[j] * (i & (1ll << j) ? 1 : -1);
        }
        s.push_back(now); t.push_back({now, i});
    }
    s.push_back(INF); sort(all(s)); sort(all(t));
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];

    ll cy = 0;
    for(int i = 1;i <= n;i += 2){
        vy[cy].push_back(a[i]);
        cy ^= 1;
    }

    ll cx = 0;
    for(int i = 2;i <= n;i += 2){
        vx[cx].push_back(a[i]);
        cx ^= 1;
    }

    for(int i = 0;i <= 1;i++){
        init(vx[i], sx[i], tx[i]);
        init(vy[i], sy[i], ty[i]);
    }

    for(auto& i : sy[0]){
        ll num = k - i;
        if(*lower_bound(all(sy[1]), num) != num) continue;
        ry = {i, num};
    }

    for(auto& i : sx[0]){
        ll num = m - i;
        if(*lower_bound(all(sx[1]), num) != num) continue;
        rx = {i, num};
    }

    if(ry.x == MINF || rx.x == MINF) {cout << "No"; return; }
    cout << "Yes\n";

    ll szx[2] = {(ll)vx[0].size() - 1, (ll)vx[1].size() - 1};
    ll szy[2] = {(ll)vy[0].size() - 1, (ll)vy[1].size() - 1};
    cy ^= 1; cx ^= 1; ll cnt = (n % 2) ^ 1;

    pll kx[2] = {{rx.x, 0}, {rx.y, 0}}, ky[2] = {{ry.x, 0}, {ry.y, 0}};
    ll nx[2] = {lower_bound(all(tx[0]), kx[0])->y, lower_bound(all(tx[1]), kx[1])->y};
    ll ny[2] = {lower_bound(all(ty[0]), ky[0])->y, lower_bound(all(ty[1]), ky[1])->y};

    while(1){
        ll cur = (cnt ? nx[cx] & (1ll << szx[cx]) : ny[cy] & (1ll << szy[cy]));
        ll pre = (!cnt ? nx[cx] & (1ll << szx[cx]) : ny[cy] & (1ll << szy[cy]));
        if(szx[cx] == -1) pre = 1;
        
        if(!cnt){
            if(cur) result.push_back(pre ? 'L' : 'R');
            else result.push_back(pre ? 'R' : 'L');
            szy[cy]--; cy ^= 1;
        }
        else{
            if(szx[cx] == -1) break;
            if(cur) result.push_back(pre ? 'R' : 'L');
            else result.push_back(pre ? 'L' : 'R');
            szx[cx]--; cx ^= 1;
        }
        cnt ^= 1;
    }

    reverse(all(result));
    for(auto& i : result) cout << i;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
