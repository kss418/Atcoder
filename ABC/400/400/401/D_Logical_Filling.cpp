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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], all, dp[MAX][2];

ll solve(ll cur, ll cnt){
    if(cur < 0) return 0;
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;

    if(cnt && s[cur] == '.') return ret;
    if(!cnt && s[cur] == 'o') return ret;

    if(cnt) ret += solve(cur - 1, 0) + 1;
    else ret += max(solve(cur - 1, 0), solve(cur - 1, 1));

    return ret;
}

void run(){
    cin >> n >> m >> s;
    for(int i = 0;i < n;i++){
        if(s[i] == 'o') all++;
        if(s[i] != '?') continue;
        if(i > 0 && i < n - 1){
            if(s[i - 1] == 'o' || s[i + 1] == 'o') s[i] = '.';
        } 
        else if(i == n - 1){
            if(s[i - 1] == 'o') s[i] = '.';
        }
        else{
            if(s[i + 1] == 'o') s[i] = '.';
        }
    }

    if(m == all){
        for(auto& i : s){
            if(i == '?') cout << '.';
            else cout << i;
        }
        return;
    }

    memset(dp, -1, sizeof(dp));
    ll able = max(solve(n - 1, 0), solve(n - 1, 1));

    string l = s, r = s; ll cnt = m - all;
    for(int i = 0;i < n;i++){
        if(l[i] != '?') continue;
        if(i > 0 && i < n - 1){
            if(l[i - 1] != 'o' && l[i + 1] != 'o' && cnt) l[i] = 'o', cnt--;
            else l[i] = '.';
        } 
        else if(i == n - 1){
            if(l[i - 1] != 'o' && cnt) l[i] = 'o', cnt--;
            else l[i] = '.';
        }
        else{
            if(l[i + 1] != 'o' && cnt) l[i] = 'o', cnt--;
            else l[i] = '.';
        }
    }

    cnt = m - all;
    for(int i = n - 1;i >= 0;i--){
        if(r[i] != '?') continue;
        if(i > 0 && i < n - 1){
            if(r[i - 1] != 'o' && r[i + 1] != 'o' && cnt) r[i] = 'o', cnt--;
            else r[i] = '.';
        } 
        else if(i == n - 1){
            if(r[i - 1] != 'o' && cnt) r[i] = 'o', cnt--;
            else r[i] = '.';
        }
        else{
            if(r[i + 1] != 'o' && cnt) r[i] = 'o', cnt--;
            else r[i] = '.';
        }
    }

    if(able > m){ cout << s; return; }
    for(int i = 0;i < n;i++){
        if(l[i] == r[i]) cout << l[i];
        else cout << '?';
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

