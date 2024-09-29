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
class query{
public:
    ll n, p, v;
};
stack <query> st;
ll cx, cy;
ll ux[MAX], uy[MAX];
set <ll> lis;
ll result[MAX];

int main() {
    fastio;

    cin >> n >> m >> k;
    cx = m; cy = n;
    result[0] = n * m;

    while(k--){
        ll n, p, v;
        cin >> n >> p >> v;
        st.push({n, p, v});
    }

    lis.insert(0);
    while(!st.empty()){
        auto [n, p, v] = st.top(); st.pop();
        if(n == 1){
            if(uy[p]) continue;
            uy[p] = 1;
            cy--; result[v] += cx;
            result[0] -= cx;
            if(result[v])lis.insert(v);
        }
        else{
            if(ux[p]) continue;
            ux[p] = 1;
            cx--; result[v] += cy;
            result[0] -= cy;
            if(result[v])lis.insert(v);
        }
    }

    if(!result[0]) lis.erase(0);
    cout << lis.size() << "\n";
    for(auto& i : lis){
        cout << i << " " << result[i] << "\n";
    }
    
  
    return 0;
}
