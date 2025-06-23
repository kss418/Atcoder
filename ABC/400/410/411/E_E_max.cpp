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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][7], cnt[MAX];
vector <ll> num;
map <ll, vector<ll>> idx;
map <ll, ll> nxt;

class _inv {
public:
    _inv() {}
    ll pow_mod(ll a, ll b, ll c) {
        if (!b) return 1;
        ll ret = pow_mod(a, b / 2, c) % c;

        if (b % 2) return ((ret * ret) % c * (a % c)) % c;
        return (ret * ret) % c;
    }

    ll prime_inv(ll a, ll b) {
        return pow_mod(a, b - 2, b);
    }

    ll ret(ll a, ll b, ll m) { // (a * b^-1) % m 반환 m == prime
        return (a % m * prime_inv(b, m) % m) % m;
    }
}; _inv inv;

class _pow {
public:
    _pow() {}

    ll ret(ll a, ll b){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a;
            a *= a; b >>= 1;
        }      
        return ret;
    }

    ll ret(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
};

void run(){
    cin >> n; _pow pow; _inv inv;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 6;j++){
            cin >> a[i][j], num.push_back(a[i][j]);
            idx[a[i][j]].push_back(i);
        }
    }

    ll inv6n = inv.ret(1, pow.ret(6, n, MOD), MOD);
    ll in[7] = {};
    for(int i = 1;i <= 6;i++) in[i] = inv.ret(1, i, MOD);

    sort(all(num));
    ll zero = n, now = 1, result = (--idx.end())->x, pre = 0;
    result %= MOD;

    for(auto& [x, y] : idx){
        nxt[pre] = x;
        pre = x;
    }

    idx.erase(--idx.end());
    for(auto& [x, y] : idx){
        for(auto& i : y){
            if(!cnt[i]) zero--;
            else now *= in[cnt[i]], now %= MOD;

            cnt[i]++;
            now *= cnt[i]; now %= MOD;
        }

        result -= (zero ? 0 : now) * (nxt[x] - x) % MOD * inv6n % MOD;
        result = (result % MOD + MOD) % MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

