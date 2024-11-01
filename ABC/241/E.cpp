#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll a[MAX];
bool v[MAX];
vector <ll> cycle;
stack <ll> st;

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i];

    ll cur = 0, sum = 0, result = 0;
    while(1){
        if(v[cur]) {
            while(st.top() != cur){
                sum += a[st.top()];
                cycle.push_back(st.top());
                st.pop();
            }

            sum += a[cur];
            cycle.push_back(cur);
            reverse(all(cycle));
            break;
        }

        v[cur] = 1;
        st.push(cur);
        cur = (cur + a[cur]) % n;
    }
    
    cur = 0;
    while(1){
        if(!m) break;
        if(cur == cycle[0]) break;
        m--; result += a[cur]; cur = result % n;
    }
    
    result += (m / cycle.size()) * sum;
    m %= cycle.size();
    cur = cycle[0];
    while(m--){
        result += a[cur];
        cur = result % n;
    }

    cout << result;
    
    return 0;
}
