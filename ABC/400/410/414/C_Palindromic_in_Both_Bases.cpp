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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result;

bool chk(ll cur){
    string now;
    while(cur){
        ll mod = cur % n;
        now.push_back(mod + '0');
        cur /= n;
    }

    for(int i = 0;i < now.size();i++){
        if(now[i] != now[now.size() - i - 1]) return 0;
    }

    return 1;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= 9;i++){
        if(i > m) break;
        if(chk(i)) result += i;
    }

    ll now = 1;
    while(1){
        string a = to_string(now), b = to_string(now);
        reverse(all(b));

        string st = a + b;
        ll cur = stoll(st);
        if(cur > m) break;
        if(chk(cur)) result += cur;
        now++;
    }

    now = 1;
    while(1){
        bool flag = 0;
        for(int i = 0;i <= 9;i++){
            string a = to_string(now), b = to_string(now);
            reverse(all(b));

            string st = a + to_string(i) + b;
            ll cur = stoll(st);
            if(cur > m) { flag = 1; break; } 
            if(chk(cur)) result += cur;
        }

        if(flag) break;
        now++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}