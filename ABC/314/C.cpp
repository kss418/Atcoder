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
ll c[MAX];
vector <ll> num[MAX];

int main() {
    fastio;

    cin >> n >> m >> s;
    for(int i = 0;i < n;i++) {
        cin >> c[i];
        num[c[i]].push_back(i);
    }

    string result; result.resize(n);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < num[i].size();j++){
            result[num[i][j]] = s[num[i][(j - 1 + num[i].size()) %  num[i].size()]];
        }
    }
    
    cout << result;
  

    return 0;
}