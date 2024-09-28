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
constexpr ll MAX = 21;
constexpr ll MOD = 998244353;
string st[MAX];

int main() {
    fastio;

    ll result = 0;
    for(int i = 1;i <= 12;i++) {
        cin >> st[i];
        if(st[i].size() == i) result++;
    }

    cout << result;
    
  
    return 0;
}
