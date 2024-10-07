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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
deque <char> st;

int main() {
    fastio;

    ll a, b; cin >> n >> a >> b >> s;
    for(auto& i : s) st.push_back(i);

    ll result = INF;
    for(int i = 0;i < n;i++){
        string cur; ll cost = a * i;
        for(auto& i : st) cur.push_back(i);
        for(int i = 0;i <= (n - 1) / 2;i++){
            if(cur[i] != cur[n - i - 1]) cost += b;
        }

        result = min(cost, result);
        ll fr = st.front();
        st.pop_front(); st.push_back(fr);
    }
    
    cout << result;


    return 0;
}
