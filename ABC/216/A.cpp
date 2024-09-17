#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;



int main() {
    fastio;
    
    cin >> s;
    for (int i = 0; i < s.size() - 2; i++) cout << s[i];
    if (s.back() >= '7') cout << "+";
    else if (s.back() >= '3') cout << "";
    else cout << "-";

    

    return 0;
}
