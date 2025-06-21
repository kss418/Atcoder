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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
string st[MAX]; ll sum;

int main() {
    fastio;

    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> st[i] >> m;
        sum += m;
    }
    sort(st, st + n);

    cout << st[sum % n];
    
  
    return 0;
}
