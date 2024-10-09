#include <bits/stdc++.h>
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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
ll a[MAX]; stack <ll> st;
bool v[MAX];

int main() {
    fastio;

    cin >> n >> m;
    
    st.push(1);
    ll cur = 1, pre = -1, nxt = -1;
    while(1){
        v[cur] = 1;
        if(cur == n) {
            cin >> s; break;
        }
        cin >> k;
        vector <ll> adj; ll flag = 0;
        for(int i = 1;i <= k;i++) {
            cin >> t, adj.push_back(t);
            if(!v[t]) flag = 1, nxt = t;
        }

        if(!flag) st.pop(), nxt = st.top();
        else cur = nxt, st.push(cur);

        cout << nxt << endl;
        cout.flush();
    }


    return 0;
}
