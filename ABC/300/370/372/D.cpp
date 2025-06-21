#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll h[MAX], result[MAX];
stack <ll> st;

int main() {
    fastio;
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = n; i >= 1; i--) {
        result[i] = st.size();
        while (!st.empty() && st.top() < h[i]) {
            st.pop();
        }
        st.push(h[i]);
    }
   
    for (int i = 1; i <= n; i++) cout << result[i] << " ";


    return 0;
}
