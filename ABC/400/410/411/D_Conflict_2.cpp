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
ll cnt, org[MAX], sev;
pair <string, ll> num[MAX];
vector <string> result;

void run(){
    cin >> n >> m;
    while(m--){
        ll op, idx; cin >> op >> idx;
        if(op == 1) org[idx] = sev;
        else if(op == 2){
            cin >> s;
            num[++cnt] = {s, org[idx]};
            org[idx] = cnt;
        }
        else sev = org[idx]; 
    }

    while(sev){
        result.push_back(num[sev].x);
        sev = num[sev].y;
    }

    reverse(all(result));
    for(auto& i : result) cout << i;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

