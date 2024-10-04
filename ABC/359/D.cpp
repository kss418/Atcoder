#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
map <pair <ll, string>, ll> dp;

string push(string st, char c){
    st.push_back(c);
    if(st.size() > m) st.erase(st.begin());

    return st;
}

bool pal(string& cur){
    if(cur.size() < m) return 1;
    string rev = cur; reverse(all(rev));
    
    return (rev == cur) ^ 1;
}

ll solve(ll cur, string st){
    if(!pal(st)) return 0;
    if(dp.count({cur, st})) return dp[{cur, st}];
    if(cur == n) return 1;

    ll ret = 0;
    if(s[cur] == '?'){
        ret += solve(cur + 1, push(st, 'A')) % MOD;
        ret += solve(cur + 1, push(st, 'B')) % MOD;
    }
    else ret = solve(cur + 1, push(st, s[cur])) % MOD;

    return dp[{cur, st}] = ret % MOD;
}

int main() {
    fastio;

    cin >> n >> m >> s;
    cout << solve(0, "");


    return 0;
}
