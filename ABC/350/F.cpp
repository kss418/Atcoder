#include <bits/stdc++.h>
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
constexpr ll MAX = 501010;
constexpr ll MOD = 998244353;
deque <ll> st;
ll skip[MAX];

void solve(ll l, ll r, ll rev){
    if(rev){
        while(l <= r){
            if(s[r] == ')'){
                solve(skip[r] + 1, r - 1, 0);
                r = skip[r];
            }
            else cout << s[r]; r--;
        }
    }
    else{
        while(l <= r){
            if(s[l] == '('){
                solve(l + 1, skip[l] - 1, 1);
                l = skip[l];
            }
            else cout << s[l]; l++;
        }
    }
}

int main() {
    fastio;

    cin >> s; ll cnt = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '(') cnt++, st.push_back(i);
        else if(s[i] == ')') {
            skip[i] = st.back();
            skip[st.back()] = i;
            st.pop_back(); cnt--;
        }
        else if(cnt % 2) s[i] ^= 32;
    }

    solve(0, s.size() - 1, 0);

    
    return 0;
}
