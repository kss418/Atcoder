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
vector <ll> idx;
ll result;

ll sum(ll cur){
    return (cur + 1) * cur / 2;
}

void run(){
    cin >> n >> s;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '1') idx.push_back(i);
    }

    ll mid = idx[(idx.size() - 1) / 2];
    for(auto& i : idx) {
        if(i == mid) continue;
        result += abs(i - mid);
    }

    ll pre = (idx.size() - 1) / 2;
    ll suf = (idx.size() - 1) / 2 + ((idx.size() + 1) % 2);

    cout << result - sum(pre) - sum(suf);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

