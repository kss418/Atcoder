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
class node{
public:
    ll a, c, n;
    bool operator<(node& ot){
        return a < ot.a;
    }
};
node arr[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> arr[i].a >> arr[i].c;
        arr[i].n = i;
    }
    sort(arr + 1, arr + n + 1);
    
    stack <pll> st;
    for(int i = 1;i <= n;i++){
        while(!st.empty() && st.top().x > arr[i].c) st.pop();
        st.push({arr[i].c, arr[i].n});
    }
    
    vector <ll> result;
    while(!st.empty()){
        result.push_back(st.top().y);
        st.pop();
    }
    sort(all(result));

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
    
  
    return 0;
}
