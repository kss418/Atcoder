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
string st[MAX];
vector <string> result;
vector <ll> vec;

void bt(){
    if(vec.size() == m){
        string now;
        for(auto& i : vec) now += st[i];
        result.push_back(now);
        return;
    }

    for(int i = 0;i < n;i++){
        vec.push_back(i);
        bt();
        vec.pop_back();
    }
}

void run(){
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) cin >> st[i];
    bt(); sort(all(result));

    cout << result[k - 1];
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

