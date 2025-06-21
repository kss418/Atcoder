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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp1[MAX], dp2[MAX];
string st1[MAX], st2[MAX];

ll solve2(ll);

ll solve1(ll cur){
    if(cur <= 0) return INF;
    ll& ret = dp1[cur];
    if(ret != -1) return ret; ret = INF;

    for(int i = 1;i < cur;i++){
        if(ret > solve1(i) + solve1(cur - i) + 1){
            ret = solve1(i) + solve1(cur - i) + 1;
            st1[cur] = st1[i] + "+" + st1[cur - i];
        }
    }

    for(int i = 2;i * i <= cur;i++){
        if(cur % i) continue;
        if(ret > solve2(i) + solve2(cur / i) + 1){
            ret = solve2(i) + solve2(cur / i) + 1;
            st1[cur] = st2[i] + "*" + st2[cur / i];
        }
    }
    
    return ret;
}

ll solve2(ll cur){
    if(cur <= 0) return INF;
    ll& ret = dp2[cur];
    if(ret != -1) return ret; ret = INF;

    for(int i = 1;i < cur;i++){
        if(ret > solve1(i) + solve1(cur - i) + 3){
            ret = solve1(i) + solve1(cur - i) + 3;
            st2[cur] = "(" + st1[i] + "+" + st1[cur - i] + ")";
        }
    }

    for(int i = 2;i * i <= cur;i++){
        if(cur % i) continue;
        if(ret > solve2(i) + solve2(cur / i) + 1){
            ret = solve2(i) + solve2(cur / i) + 1;
            st2[cur] = st2[i] + "*" + st2[cur / i];
        }
    }

    return ret;
}

void run(){
    cin >> n; memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));

    ll now = 1, cnt = 1;
    while(now <= 1111){
        dp1[now] = dp2[now] = cnt;
        st1[now] = st2[now] = to_string(now);
        now *= 10; now++; cnt++;
    }

    solve1(n);
    cout << st1[n];
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

