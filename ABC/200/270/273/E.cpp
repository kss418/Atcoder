#include <bits/stdc++.h>
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
pair <string, ll> query[MAX];
vector <ll> nxt[MAX];
map <ll, ll> sidx; ll result[MAX], q;
bool v[MAX]; stack <ll> st;


ll top(){
    if(!st.empty()) return st.top();
    return -1;
}

ll add(ll num){
    st.push(num);
    return top();
}

ll del(){
    if(!st.empty()) st.pop();
    return top();
}

void dfs(ll cur){
    if(cur > q) return; 

    for(auto& idx : nxt[cur]){
        stack <pll> use;
        while(1){
            auto cq = query[idx];
            if(idx > q || v[idx]) break;
            v[idx] = 1;

            if(cq.x == "ADD") result[idx] = add(cq.y), use.push({0, -1});
            else if(cq.x == "DELETE") use.push({1, top()}), result[idx] = del();
            else if(cq.x == "SAVE") result[idx] = top(), dfs(idx);
            else result[idx] = top(); 
        
            idx++; if(query[idx].x == "LOAD") break;
        }

        while(!use.empty()){
            auto [cc, ct] = use.top(); use.pop();
            if(!cc) st.pop();
            else if(ct != -1) st.push(ct);
        }
    }
}

int main() {
    fastio;

    cin >> q;
    for(int i = 1;i <= q;i++){
        string com; ll x; cin >> com;
        if(com != "DELETE") cin >> x;
        else x = -1;

        nxt[i].push_back(i);
        query[i] = {com, x};
        if(com == "SAVE") sidx[x] = i;
        else if(com == "LOAD") {
            nxt[sidx[x]].push_back(i);
        }
    }

    for(int i = 0;i <= q;i++) if(!v[i]) dfs(i);

    for(int i = 1;i <= q;i++) cout << result[i] << " ";

    
    return 0;
}
